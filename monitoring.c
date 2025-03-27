/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:53:24 by juduchar          #+#    #+#             */
/*   Updated: 2025/03/27 15:29:18 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_all_philos_ate_enough(t_monitoring *monitoring)
{
	int	i;
	int	meals_eaten;

	i = 0;
	while (i < monitoring->data->number_of_philosophers)
	{
		pthread_mutex_lock(&monitoring->philo[i].meals_eaten_mutex);
		meals_eaten = monitoring->philo[i].meals_eaten;
		if (meals_eaten < monitoring->data->meals_required)
		{
			pthread_mutex_unlock(&monitoring->philo[i].meals_eaten_mutex);
			return (0);
		}
		pthread_mutex_unlock(&monitoring->philo[i].meals_eaten_mutex);
		i++;
	}
	if (!ft_mutex_is_simulation_finished(monitoring))
	{
		pthread_mutex_lock(&monitoring->data->printf_mutex);
		printf("all philos ate enough\n");
		pthread_mutex_unlock(&monitoring->data->printf_mutex);
	}
	return (1);
}

int	ft_check_philo_starve(t_monitoring *monitoring)
{
	long	time_in_ms;
	int		i;
	long	last_meal_time;

	i = 0;
	while (i < monitoring->data->number_of_philosophers)
	{
		pthread_mutex_lock(&monitoring->philo[i].last_meal_time_mutex);
		last_meal_time = monitoring->philo[i].last_meal_time;
		pthread_mutex_unlock(&monitoring->philo[i].last_meal_time_mutex);
		time_in_ms = ft_get_time_in_ms();
		if (time_in_ms - last_meal_time > monitoring->data->time_to_die)
		{
			pthread_mutex_lock(&monitoring->data->printf_mutex);
			printf("[%ldms] %d %s", ft_get_time_in_ms() - monitoring->data->start_time_in_ms,
				monitoring->philo[i].id, "died\n");
			pthread_mutex_unlock(&monitoring->data->printf_mutex);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*ft_monitoring(void *param)
{
	t_monitoring	*monitoring;

	monitoring = (t_monitoring *)param;
	while (!ft_mutex_is_simulation_finished(monitoring))
	{
		usleep(1000);
		if (ft_check_philo_starve(monitoring) == 1)
		{
			pthread_mutex_lock(&monitoring->simulation_finished_mutex);
			monitoring->simulation_finished = 1;
			pthread_mutex_unlock(&monitoring->simulation_finished_mutex);
		}
		else if (monitoring->data->meals_required != 0
			&& ft_check_all_philos_ate_enough(monitoring) == 1)
		{
			pthread_mutex_lock(&monitoring->simulation_finished_mutex);
			monitoring->simulation_finished = 1;
			pthread_mutex_unlock(&monitoring->simulation_finished_mutex);
		}
	}
	return (NULL);
}
