/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:42:32 by julien            #+#    #+#             */
/*   Updated: 2025/04/12 17:50:29 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_join_monitoring_thread(t_monitoring *monitoring)
{
	pthread_join(monitoring->thread_id, NULL);
}

static void	ft_join_philos_threads(t_table *table, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		pthread_join(philo[i].thread_id, NULL);
		i++;
	}
}

void	ft_join_monitoring_and_philos_threads(t_table *table,
	t_monitoring *monitoring, t_philo *philo)
{
	ft_join_monitoring_thread(monitoring);
	ft_join_philos_threads(table, philo);
}
