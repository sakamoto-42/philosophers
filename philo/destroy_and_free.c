/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_and_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:25:26 by julien            #+#    #+#             */
/*   Updated: 2025/04/12 18:32:56 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_destroy_and_free_table(t_table *table)
{
	int	i;

	pthread_mutex_destroy(&table->printf_mutex);
	i = 0;
	while (i < table->number_of_philosophers)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	free(table->forks);
	table->forks = NULL;
}

void	ft_destroy_and_free_monitoring(t_monitoring **monitoring)
{
	pthread_mutex_destroy(&(*monitoring)->simulation_finished_mutex);
	free(*monitoring);
	*monitoring = NULL;
}

void	ft_destroy_and_free_philos(t_table *table, t_philo **philo)
{
	int	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		pthread_mutex_destroy(&(*philo)[i].meals_eaten_mutex);
		pthread_mutex_destroy(&(*philo)[i].last_meal_time_mutex);
		i++;
	}
	free(*philo);
	*philo = NULL;
}

void	ft_destroy_and_free_all(t_table *table,
	t_monitoring **monitoring, t_philo **philo)
{
	ft_destroy_and_free_table(table);
	ft_destroy_and_free_monitoring(monitoring);
	ft_destroy_and_free_philos(table, philo);
}
