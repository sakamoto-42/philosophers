/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:44:55 by juduchar          #+#    #+#             */
/*   Updated: 2025/03/27 15:58:19 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_meals_eaten(t_philo *philo)
{
	long	timestamp_in_ms;
	int		meals_eaten;

	pthread_mutex_lock(&philo->meals_eaten_mutex);
	meals_eaten = philo->meals_eaten;
	pthread_mutex_unlock(&philo->meals_eaten_mutex);
	pthread_mutex_lock(&philo->data->printf_mutex);
	if (!ft_mutex_is_simulation_finished(philo->monitoring))
	{
		timestamp_in_ms = ft_get_time_in_ms() - philo->data->start_time_in_ms;
		printf("[%ldms] philo %d ate %d meal(s)\n", timestamp_in_ms, philo->id, meals_eaten);
	}
	pthread_mutex_unlock(&philo->data->printf_mutex);
}

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
	ft_print_meals_eaten(philo);
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
