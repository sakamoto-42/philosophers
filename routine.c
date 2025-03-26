/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:17:34 by julien            #+#    #+#             */
/*   Updated: 2025/03/26 15:39:23 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo_routine(void *param)
{
	t_philo			*philo;

	philo = (t_philo *)param;
	while (!ft_mutex_is_simulation_finished(philo->monitoring)
		&& (philo->data->meals_required == 0
			|| (philo->meals_eaten < philo->data->meals_required)))
	{
		ft_eat(philo);
		pthread_mutex_lock(&philo->data->printf_mutex);
		printf("%d has eaten %d times\n", philo->id, philo->meals_eaten);
		pthread_mutex_unlock(&philo->data->printf_mutex);
		ft_sleep(philo);
		ft_think(philo);
	}
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
