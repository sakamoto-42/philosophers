/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:35:52 by julien            #+#    #+#             */
/*   Updated: 2025/04/12 18:41:27 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_alloc_monitoring_and_philos(t_table *table,
	t_monitoring **monitoring, t_philo **philo)
{
	if (ft_alloc_monitoring(monitoring) == ERROR)
		return (ERROR);
	if (ft_alloc_philos(table, philo) == ERROR)
	{
		ft_free_monitoring(monitoring);
		return (ERROR);
	}
	return (SUCCESS);
}

static int	ft_init_monitoring_and_philos(t_table *table,
	t_monitoring **monitoring, t_philo **philo)
{
	if (ft_init_monitoring(table, *monitoring, *philo) == ERROR)
	{
		ft_free_monitoring(monitoring);
		return (ERROR);
	}
	if (ft_init_philos(table, *monitoring, *philo) == ERROR)
	{
		ft_destroy_and_free_monitoring(monitoring);
		return (ERROR);
	}
	return (SUCCESS);
}

int	ft_alloc_and_init_monitoring_and_philos(t_table *table,
	t_monitoring **monitoring, t_philo **philo)
{
	if (ft_alloc_monitoring_and_philos(table, monitoring, philo) == ERROR)
	{
		ft_destroy_and_free_table(table);
		return (ERROR);
	}
	if (ft_init_monitoring_and_philos(table, monitoring, philo) == ERROR)
	{
		ft_destroy_and_free_table(table);
		ft_free_philo(philo);
		return (ERROR);
	}
	return (SUCCESS);
}
