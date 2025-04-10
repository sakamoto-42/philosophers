/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:35:52 by julien            #+#    #+#             */
/*   Updated: 2025/04/10 15:36:44 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_alloc_and_init_monitoring_and_philos(t_table *table,
	t_monitoring **monitoring, t_philo **philo)
{
	if (ft_alloc_monitoring(monitoring) == ERROR)
		return (ERROR);
	if (ft_alloc_philos(table, philo) == ERROR)
		return (ERROR);
	if (ft_init_monitoring(table, *monitoring, *philo) == ERROR)
		return (ERROR);
	if (ft_init_philos(table, *monitoring, *philo) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
