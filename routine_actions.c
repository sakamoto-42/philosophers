/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:44:55 by juduchar          #+#    #+#             */
/*   Updated: 2025/03/27 15:35:30 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	if (ft_mutex_is_simulation_finished(philo->monitoring))
		return ;
	ft_mutex_lock_forks(philo);
	if (ft_mutex_is_simulation_finished(philo->monitoring))
	{
		ft_mutex_unlock_forks(philo);
		return ;
	}
	pthread_mutex_lock(&philo->last_meal_time_mutex);
	philo->last_meal_time = ft_get_time_in_ms();
	pthread_mutex_unlock(&philo->last_meal_time_mutex);
	ft_print_info(philo, "is eating \n");
	ft_usleep_interruptible(philo->data->time_to_eat, philo);
	if (ft_mutex_is_simulation_finished(philo->monitoring))
	{
		ft_mutex_unlock_forks(philo);
		return ;
	}
	ft_mutex_unlock_forks(philo);
	pthread_mutex_lock(&philo->meals_eaten_mutex);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meals_eaten_mutex);
}

void	ft_sleep(t_philo *philo)
{
	if (ft_mutex_is_simulation_finished(philo->monitoring))
		return ;
	ft_print_info(philo, "is sleeping\n");
	ft_usleep_interruptible(philo->data->time_to_sleep, philo);
}

void	ft_think(t_philo *philo)
{
	if (ft_mutex_is_simulation_finished(philo->monitoring))
		return ;
	ft_print_info(philo, "is thinking\n");
}
