/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 09:23:00 by julien            #+#    #+#             */
/*   Updated: 2025/04/13 12:53:33 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_mutex_get_last_meal_time(t_philo *philo)
{
	long	last_meal_time;

	pthread_mutex_lock(&philo->last_meal_time_mutex);
	last_meal_time = philo->last_meal_time;
	pthread_mutex_unlock(&philo->last_meal_time_mutex);
	return (last_meal_time);
}

void	ft_mutex_set_last_meal_time(t_philo *philo, long last_meal_time)
{
	pthread_mutex_lock(&philo->last_meal_time_mutex);
	philo->last_meal_time = last_meal_time;
	pthread_mutex_unlock(&philo->last_meal_time_mutex);
}

void	ft_mutex_increment_meals_eaten(t_philo *philo)
{
	pthread_mutex_lock(&philo->meals_eaten_mutex);
	philo->meals_eaten += 1;
	pthread_mutex_unlock(&philo->meals_eaten_mutex);
}

long	ft_mutex_compute_time_to_think(t_table *table,
	t_philo *philo)
{
	long	time_to_think;

	pthread_mutex_lock(&philo->last_meal_time_mutex);
	time_to_think = (table->time_to_die
			- (ft_get_time_in_ms() - philo->last_meal_time)
			- table->time_to_eat) / 2;
	pthread_mutex_unlock(&philo->last_meal_time_mutex);
	return (time_to_think);
}
