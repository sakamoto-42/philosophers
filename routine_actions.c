/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:44:55 by juduchar          #+#    #+#             */
/*   Updated: 2025/04/10 15:10:47 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_table *table, t_monitoring *monitoring, t_philo *philo)
{
	if (!ft_mutex_is_simulation_finished(monitoring))
	{
		ft_mutex_lock_forks(table, monitoring, philo);
		ft_print_info(table, monitoring, philo, "is eating\n");
	}
	ft_usleep_interruptible(table->time_to_eat, philo);
	if (ft_mutex_is_simulation_finished(monitoring))
	{
		ft_mutex_unlock_forks(philo);
		return ;
	}
	ft_mutex_unlock_forks(philo);
	pthread_mutex_lock(&philo->meals_eaten_mutex);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meals_eaten_mutex);
	pthread_mutex_lock(&philo->last_meal_time_mutex);
	philo->last_meal_time = ft_get_time_in_ms();
	pthread_mutex_unlock(&philo->last_meal_time_mutex);
}

void	ft_sleep(t_table *table, t_monitoring *monitoring, t_philo *philo)
{
	if (ft_mutex_is_simulation_finished(monitoring))
		return ;
	ft_print_info(table, monitoring, philo, "is sleeping\n");
	ft_usleep_interruptible(table->time_to_sleep, philo);
}

void	ft_think(t_table *table, t_monitoring *monitoring, t_philo *philo)
{
	if (ft_mutex_is_simulation_finished(monitoring))
		return ;
	ft_print_info(table, monitoring, philo, "is thinking\n");
}
