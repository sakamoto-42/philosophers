/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:24:53 by julien            #+#    #+#             */
/*   Updated: 2025/04/14 22:52:43 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_kill_one_philo(t_table *table,
	t_monitoring *monitoring, t_philo *philo)
{
	if (!ft_mutex_is_simulation_finished(monitoring))
	{
		ft_mutex_set_simulation_finished(monitoring, 1);
		ft_print_info(table, monitoring, philo, "died\n");
	}
}

static void	*ft_one_philo_routine(t_table *table,
	t_monitoring *monitoring, t_philo *philo)
{
	ft_mutex_lock_one_fork(table, monitoring, philo, philo->left_fork);
	ft_usleep_interruptible(table, monitoring, table->time_to_die);
	ft_kill_one_philo(table, monitoring, philo);
	ft_mutex_unlock_one_fork(philo->left_fork);
	return (NULL);
}

static void	ft_start_routine(t_table *table,
	t_monitoring *monitoring, t_philo *philo)
{
	while (!ft_mutex_is_simulation_finished(monitoring))
	{
		ft_eat(table, monitoring, philo);
		ft_sleep(table, monitoring, philo);
		ft_think(table, monitoring, philo);
	}
}

void	*ft_philo_routine(void *param)
{
	t_philo			*philo;
	t_monitoring	*monitoring;
	t_table			*table;

	philo = (t_philo *)param;
	monitoring = philo->monitoring;
	table = monitoring->table;
	ft_mutex_set_last_meal_time(philo, table->start_time_in_ms);
	while (ft_get_time_in_ms() < table->start_time_in_ms)
		usleep(100);
	if (table->number_of_philosophers == 1)
		return (ft_one_philo_routine(table, monitoring, philo));
	if (philo->id % 2)
	{
		ft_print_info(table, monitoring, philo, "is thinking\n");
		usleep(10 * table->number_of_philosophers);
	}
	ft_start_routine(table, monitoring, philo);
	return (NULL);
}
