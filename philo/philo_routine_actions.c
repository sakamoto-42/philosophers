/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_actions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 09:15:28 by julien            #+#    #+#             */
/*   Updated: 2025/04/14 22:11:59 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_table *table, t_monitoring *monitoring, t_philo *philo)
{
	ft_mutex_lock_two_forks(table, monitoring, philo);
	if (ft_mutex_is_simulation_finished(monitoring))
	{
		ft_mutex_unlock_two_forks(philo);
		return ;
	}
	ft_mutex_set_last_meal_time(philo, ft_get_time_in_ms());
	ft_print_info(table, monitoring, philo, "is eating\n");
	ft_mutex_increment_meals_eaten(philo);
	ft_usleep_interruptible(table, monitoring, table->time_to_eat);
	ft_mutex_unlock_two_forks(philo);
}

void	ft_sleep(t_table *table, t_monitoring *monitoring, t_philo *philo)
{
	if (ft_mutex_is_simulation_finished(monitoring))
		return ;
	ft_print_info(table, monitoring, philo, "is sleeping\n");
	ft_usleep_interruptible(table, monitoring, table->time_to_sleep);
}

void	ft_think(t_table *table,
	t_monitoring *monitoring, t_philo *philo)
{
	long	time_to_think;

	if (ft_mutex_is_simulation_finished(monitoring))
		return ;
	time_to_think = ft_mutex_compute_time_to_think(table, philo);
	if (time_to_think == 0)
	{
		ft_usleep_interruptible(table, monitoring, 1);
		return ;
	}
	ft_print_info(table, monitoring, philo, "is thinking\n");
	ft_usleep_interruptible(table, monitoring, time_to_think);
}
