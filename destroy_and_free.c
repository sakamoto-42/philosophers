/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_and_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:25:26 by julien            #+#    #+#             */
/*   Updated: 2025/03/26 15:49:16 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_destroy_and_free(t_data *data, t_philo *philo, t_monitoring *monitoring)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&philo[i].meals_eaten_mutex);
		i++;
	}
	pthread_mutex_destroy(&data->printf_mutex);
	pthread_mutex_destroy(&monitoring->simulation_finished_mutex);
	free(data->forks);
	free(philo);
	free(monitoring);
}
