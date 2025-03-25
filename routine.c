/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:17:34 by julien            #+#    #+#             */
/*   Updated: 2025/03/25 16:29:20 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo_routine(void *param)
{
	t_philo			*philo;

	philo = (t_philo *)param;
	pthread_mutex_lock(philo->left_fork);
	ft_print_info(philo, "has taken a fork\n");
	pthread_mutex_lock(philo->right_fork);
	ft_print_info(philo, "has taken a fork\n");
	ft_print_info(philo, "is eating \n");
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	ft_print_info(philo, "is sleeping\n");
	usleep(philo->data->time_to_sleep * 1000);
	ft_print_info(philo, "is thinking\n");
	return (NULL);
}

void	ft_print_info(t_philo *philo, char *str)
{
	long	timestamp_in_ms;

	timestamp_in_ms = ft_get_time_in_ms() - philo->data->start_time_in_ms;
	pthread_mutex_lock(&philo->data->printf_mutex);
	printf("[%ldms] %d %s", timestamp_in_ms, philo->id, str);
	pthread_mutex_unlock(&philo->data->printf_mutex);
}
