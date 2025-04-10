/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:42:32 by julien            #+#    #+#             */
/*   Updated: 2025/04/10 15:07:31 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_join_monitoring_thread(t_monitoring *monitoring)
{
	if (pthread_join(monitoring->thread_id, NULL) != 0)
	{
		ft_print_error("Error: pthread_join monitoring failed\n");
		return (ERROR);
	}
	return (SUCCESS);
}

static int	ft_join_philos_threads(t_table *table, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		if (pthread_join(philo[i].thread_id, NULL) != 0)
		{
			ft_print_error("Error: pthread_join ");
			ft_print_error(ft_itoa(i + 1));
			ft_print_error(" failed\n");
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int	ft_join_monitoring_and_philos_threads(t_table *table,
	t_monitoring *monitoring, t_philo *philo)
{
	if (ft_join_monitoring_thread(monitoring) == ERROR)
		return (ERROR);
	if (ft_join_philos_threads(table, philo) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
