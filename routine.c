/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:17:34 by julien            #+#    #+#             */
/*   Updated: 2025/03/27 15:56:56 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo_routine(void *param)
{
	t_philo			*philo;

	philo = (t_philo *)param;
	if (philo->data->number_of_philosophers == 1)
		return (ft_one_philo_routine(philo));
	while (!ft_mutex_is_simulation_finished(philo->monitoring)
		&& (philo->data->meals_required == 0
			|| (philo->meals_eaten < philo->data->meals_required)))
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}

void	*ft_one_philo_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	ft_print_info(philo, "has taken a fork\n");
	ft_usleep_interruptible(philo->data->time_to_die, philo);
	pthread_mutex_unlock(philo->left_fork);
	return (NULL);
}

void	ft_print_info(t_philo *philo, char *str)
{
	long	timestamp_in_ms;

	pthread_mutex_lock(&philo->data->printf_mutex);
	if (!ft_mutex_is_simulation_finished(philo->monitoring))
	{
		timestamp_in_ms = ft_get_time_in_ms() - philo->data->start_time_in_ms;
		printf("[%ldms] philo %d %s", timestamp_in_ms, philo->id, str);
	}
	pthread_mutex_unlock(&philo->data->printf_mutex);
}
