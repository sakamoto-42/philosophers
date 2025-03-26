/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:53:24 by juduchar          #+#    #+#             */
/*   Updated: 2025/03/26 14:08:15 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_all_philos_ate_enough(t_monitoring *monitoring)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < monitoring->data->number_of_philosophers)
	{
		if (monitoring->philo[i].meals_eaten >= monitoring->data->number_of_times_each_philosopher_must_eat)
			count++;
		i++;
	}
	return (count == monitoring->data->number_of_philosophers);
}

void	*ft_monitoring(void *param)
{
	t_monitoring	*monitoring;
	int				result;

	monitoring = (t_monitoring *)param;
	while (!ft_mutex_is_simulation_finished(monitoring))
	{
		if (monitoring->data->number_of_times_each_philosopher_must_eat != 0)
		{
			result = ft_check_all_philos_ate_enough(monitoring);
			pthread_mutex_lock(&monitoring->simulation_finished_mutex);
			monitoring->simulation_finished = 1;
			pthread_mutex_unlock(&monitoring->simulation_finished_mutex);
		}
		usleep(100 * 1000);
	}
	return (NULL);
}

