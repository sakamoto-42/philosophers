/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_init_philos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:05:41 by julien            #+#    #+#             */
/*   Updated: 2025/04/14 22:47:06 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_set_forks(t_philo *philo, int i, t_table *table)
{
	int	right_philo_index;

	right_philo_index = (i + 1) % table->number_of_philosophers;
	philo[i].left_fork = &table->forks[i];
	philo[i].right_fork = &table->forks[right_philo_index];
}

int	ft_alloc_philos(t_table *table, t_philo **philo)
{
	*philo = malloc(table->number_of_philosophers * sizeof(t_philo));
	if (!*philo)
	{
		ft_print_error("Error: malloc failed\n");
		return (ERROR);
	}
	memset(*philo, 0, table->number_of_philosophers * sizeof(t_philo));
	return (SUCCESS);
}

int	ft_init_philos(t_table *table,
	t_monitoring *monitoring, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		philo[i].id = i + 1;
		ft_set_forks(philo, i, table);
		philo[i].meals_eaten = 0;
		if (pthread_mutex_init(&philo[i].meals_eaten_mutex, NULL) != 0)
			return (ERROR);
		philo[i].last_meal_time = ft_get_time_in_ms();
		if (pthread_mutex_init(&philo[i].last_meal_time_mutex, NULL) != 0)
			return (ERROR);
		philo[i].monitoring = monitoring;
		i++;
	}
	return (SUCCESS);
}
