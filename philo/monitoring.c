/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:24:48 by julien            #+#    #+#             */
/*   Updated: 2025/04/14 22:35:15 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_philo_starve(t_monitoring *monitoring,
	t_table *table, t_philo *philo)
{
	long	now;
	long	last_meal_time;

	now = ft_get_time_in_ms();
	last_meal_time = ft_mutex_get_last_meal_time(philo);
	if ((now - last_meal_time) >= table->time_to_die)
	{
		ft_mutex_set_simulation_finished(monitoring, 1);
		pthread_mutex_lock(&table->printf_mutex);
		printf("%lu %d died\n",
			ft_get_time_in_ms() - table->start_time_in_ms, philo->id);
		pthread_mutex_unlock(&table->printf_mutex);
		return (1);
	}
	return (0);
}

int	ft_check_philo_ate_enough(t_table *table, t_philo *philo)
{
	int	ate_enough;

	pthread_mutex_lock(&philo->meals_eaten_mutex);
	ate_enough = (philo->meals_eaten >= table->meals_required);
	pthread_mutex_unlock(&philo->meals_eaten_mutex);
	return (ate_enough);
}

static int	ft_check_simulation_must_finish(t_table *table,
	t_monitoring *monitoring, t_philo *philo)
{
	int	i;
	int	all_meals_eaten;

	i = 0;
	all_meals_eaten = 1;
	while (i < table->number_of_philosophers)
	{
		if (ft_philo_starve(monitoring, table, &philo[i]))
			return (1);
		if (table->meals_required != -1)
		{
			if (!ft_check_philo_ate_enough(table, &philo[i]))
				all_meals_eaten = 0;
		}
		i++;
	}
	if (table->meals_required != -1 && all_meals_eaten == 1)
	{
		ft_mutex_set_simulation_finished(monitoring, 1);
		return (1);
	}
	return (0);
}

void	*ft_monitoring(void *param)
{
	t_monitoring	*monitoring;
	t_table			*table;
	t_philo			*philo;

	monitoring = (t_monitoring *)param;
	table = monitoring->table;
	philo = monitoring->philo;
	while (ft_get_time_in_ms() < table->start_time_in_ms)
		usleep(table->number_of_philosophers);
	while (!ft_check_simulation_must_finish(table, monitoring, philo))
		usleep(table->number_of_philosophers);
	return (NULL);
}
