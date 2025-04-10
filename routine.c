/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:17:34 by julien            #+#    #+#             */
/*   Updated: 2025/04/10 15:13:30 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_one_philo_routine(t_table *table,
	t_monitoring *monitoring, t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	ft_print_info(table, monitoring, philo, "has taken a fork\n");
	ft_usleep_interruptible(table->time_to_die, philo);
	pthread_mutex_unlock(philo->left_fork);
	return (NULL);
}

void	*ft_philo_routine(void *param)
{
	t_philo			*philo;
	t_monitoring	*monitoring;
	t_table			*table;

	philo = (t_philo *)param;
	monitoring = philo->monitoring;
	table = philo->monitoring->table;

	while (table->start_time_in_ms == 0
		|| ft_get_time_in_ms() < table->start_time_in_ms)
		usleep(100);
	if (philo->id % 2 == 0)
		usleep(100);
	if (table->number_of_philosophers == 1)
		return (ft_one_philo_routine(table, monitoring, philo));
	while (!ft_mutex_is_simulation_finished(monitoring)
		&& (table->meals_required == -1
			|| philo->meals_eaten < table->meals_required))
	{
		ft_eat(table, monitoring, philo);
		ft_sleep(table, monitoring, philo);
		ft_think(table, monitoring, philo);
	}
	return (NULL);
}
