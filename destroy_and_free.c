/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_and_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:25:26 by julien            #+#    #+#             */
/*   Updated: 2025/04/10 14:03:33 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_destroy_and_free(t_table *table,
	t_monitoring *monitoring, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		pthread_mutex_destroy(&table->forks[i]);
		pthread_mutex_destroy(&philo[i].meals_eaten_mutex);
		pthread_mutex_destroy(&philo[i].last_meal_time_mutex);
		i++;
	}
	pthread_mutex_destroy(&table->printf_mutex);
	pthread_mutex_destroy(&monitoring->simulation_finished_mutex);
	free(table->forks);
	free(philo);
	free(monitoring);
}
