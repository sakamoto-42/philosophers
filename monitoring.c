/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:53:24 by juduchar          #+#    #+#             */
/*   Updated: 2025/03/26 21:35:22 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_all_philos_ate_enough(t_monitoring *monitoring)
{
	int	i;

	i = 0;
	while (i < monitoring->data->number_of_philosophers)
	{
		pthread_mutex_lock(&monitoring->philo[i].meals_eaten_mutex);
		if (monitoring->philo[i].meals_eaten < monitoring->data->meals_required)
		{
			pthread_mutex_unlock(&monitoring->philo[i].meals_eaten_mutex);
			return (0);
		}
		pthread_mutex_unlock(&monitoring->philo[i].meals_eaten_mutex);
		i++;
	}
	return (1);
}

void	*ft_monitoring(void *param)
{
	t_monitoring	*monitoring;

	monitoring = (t_monitoring *)param;
	while (!ft_mutex_is_simulation_finished(monitoring))
	{
		if (monitoring->data->meals_required != 0)
		{
			if (ft_check_all_philos_ate_enough(monitoring) == 1)
			{
				pthread_mutex_lock(&monitoring->simulation_finished_mutex);
				monitoring->simulation_finished = 1;
				pthread_mutex_unlock(&monitoring->simulation_finished_mutex);
			}
		}
		usleep(500 * 1000);
	}
	pthread_mutex_lock(&monitoring->data->printf_mutex);
	printf("ALL MEALS EATEN\n");
	pthread_mutex_unlock(&monitoring->data->printf_mutex);
	return (NULL);
}
