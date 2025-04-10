/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:53:24 by juduchar          #+#    #+#             */
/*   Updated: 2025/04/10 15:09:01 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_philo_starve(t_table *table, t_philo *philo)
{
	long	time_in_ms;
	int		i;
	long	last_meal_time;

	time_in_ms = ft_get_time_in_ms();
	i = 0;
	while (i < table->number_of_philosophers)
	{
		pthread_mutex_lock(&philo[i].last_meal_time_mutex);
		last_meal_time = philo[i].last_meal_time;
		pthread_mutex_unlock(&philo[i].last_meal_time_mutex);
		if (time_in_ms - last_meal_time >= table->time_to_die)
		{
			pthread_mutex_lock(&table->printf_mutex);
			printf("%lu %d died\n",
				time_in_ms - table->start_time_in_ms,
				philo[i].id);
			pthread_mutex_unlock(&table->printf_mutex);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	ft_check_all_philos_ate_enough(t_table *table, t_philo *philo)
{
	int	i;
	int	meals_eaten;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		pthread_mutex_lock(&philo[i].meals_eaten_mutex);
		meals_eaten = philo[i].meals_eaten;
		if (meals_eaten < table->meals_required)
		{
			pthread_mutex_unlock(&philo[i].meals_eaten_mutex);
			return (0);
		}
		pthread_mutex_unlock(&philo[i].meals_eaten_mutex);
		i++;
	}
	return (1);
}

static void	ft_set_simulation_finished(t_monitoring *monitoring)
{
	pthread_mutex_lock(&monitoring->simulation_finished_mutex);
	monitoring->simulation_finished = 1;
	pthread_mutex_unlock(&monitoring->simulation_finished_mutex);
}

void	*ft_monitoring(void *param)
{
	t_monitoring	*monitoring;
	t_table			*table;
	t_philo			*philo;

	monitoring = (t_monitoring *)param;
	table = monitoring->table;
	philo = monitoring->philo;
	while (!ft_mutex_is_simulation_finished(monitoring))
	{
		if (ft_check_philo_starve(table, philo) == 1)
		{
			ft_set_simulation_finished(monitoring);
			return (NULL);
		}
		if (table->meals_required != 0
			&& ft_check_all_philos_ate_enough(table, philo) == 1)
		{
			ft_set_simulation_finished(monitoring);
			return (NULL);
		}
		usleep(10);
	}
	return (NULL);
}
