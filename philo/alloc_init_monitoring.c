/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_init_monitoring.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:16:10 by julien            #+#    #+#             */
/*   Updated: 2025/04/11 18:49:18 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_alloc_monitoring(t_monitoring **monitoring)
{
	*monitoring = malloc(sizeof(t_monitoring));
	if (!*monitoring)
	{
		ft_print_error("Error: malloc failed\n");
		return (ERROR);
	}
	memset(*monitoring, 0, sizeof(t_monitoring));
	return (SUCCESS);
}

int	ft_init_monitoring(t_table *table,
	t_monitoring *monitoring, t_philo *philo)
{
	monitoring->table = table;
	monitoring->philo = philo;
	monitoring->simulation_finished = 0;
	if (pthread_mutex_init(&monitoring->simulation_finished_mutex, NULL) != 0)
		return (ERROR);
	return (SUCCESS);
}
