/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table_and_forks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:04:12 by julien            #+#    #+#             */
/*   Updated: 2025/04/12 18:28:47 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_init_table(t_table *table, int argc, char **argv)
{
	int	i;

	i = 1;
	table->number_of_philosophers = ft_atoi(argv[i++]);
	table->time_to_die = ft_atoi(argv[i++]);
	table->time_to_eat = ft_atoi(argv[i++]);
	table->time_to_sleep = ft_atoi(argv[i++]);
	if (argc - 1 == NB_ARGS)
		table->meals_required = ft_atoi(argv[i]);
	else
		table->meals_required = -1;
	return (SUCCESS);
}

static int	ft_init_forks(t_table **table)
{
	int	i;

	(*table)->forks = malloc((*table)->number_of_philosophers
			* sizeof(pthread_mutex_t));
	if (!(*table)->forks)
		return (ERROR);
	i = 0;
	while (i < (*table)->number_of_philosophers)
	{
		if (pthread_mutex_init(&(*table)->forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&(*table)->forks[i]);
			free((*table)->forks);
			(*table)->forks = NULL;
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int	ft_init_table_and_forks(t_table *table, int argc, char **argv)
{
	if (ft_init_table(table, argc, argv) == ERROR)
		return (ERROR);
	if (table->meals_required == 0)
		return (STOP);
	if (pthread_mutex_init(&table->printf_mutex, NULL) != 0)
		return (ERROR);
	if (ft_init_forks(&table) == ERROR)
	{
		pthread_mutex_destroy(&table->printf_mutex);
		return (ERROR);
	}
	return (SUCCESS);
}
