/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:05:02 by julien            #+#    #+#             */
/*   Updated: 2025/04/10 14:00:20 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table			table;
	t_philo			*philo;
	t_monitoring	*monitoring;

	if (ft_check_args(argc, argv) == ERROR)
		return (ERROR);
	if (ft_init_table(&table, argc, argv) == ERROR)
		return (ERROR);
	if (ft_alloc_and_init_monitoring_and_philos(&table,
			&monitoring, &philo) == ERROR)
		return (ERROR);
	if (ft_create_monitoring_and_philos_threads(&table,
			monitoring, philo) == ERROR)
		return (ERROR);
	table.start_time_in_ms = ft_get_time_in_ms();
	if (ft_join_monitoring_and_philos_threads(&table,
			monitoring, philo) == ERROR)
		return (ERROR);
	ft_destroy_and_free(&table, monitoring, philo);
	return (SUCCESS);
}
