/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:40:42 by julien            #+#    #+#             */
/*   Updated: 2025/04/10 15:06:47 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_create_monitoring_thread(t_monitoring *monitoring)
{
	if (pthread_create(&monitoring->thread_id, NULL,
			ft_monitoring, (void *)monitoring) != 0)
	{
		ft_print_error("Error: pthread_create monitoring failed\n");
		return (ERROR);
	}
	return (SUCCESS);
}

static int	ft_create_philos_threads(t_table *table, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		if (pthread_create(&philo[i].thread_id, NULL,
				ft_philo_routine, (void *)&philo[i]) != 0)
		{
			ft_print_error("Error: pthread_create ");
			ft_print_error(ft_itoa(i + 1));
			ft_print_error(" failed\n");
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int	ft_create_monitoring_and_philos_threads(t_table *table,
	t_monitoring *monitoring, t_philo *philo)
{
	if (ft_create_monitoring_thread(monitoring) == ERROR)
		return (ERROR);
	if (ft_create_philos_threads(table, philo) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
