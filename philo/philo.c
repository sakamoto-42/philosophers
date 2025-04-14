/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:24:58 by julien            #+#    #+#             */
/*   Updated: 2025/04/14 22:33:04 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_start_simulation(t_table *table,
	t_monitoring **monitoring, t_philo **philo)
{
	if (ft_create_monitoring_and_philos_threads(table,
			monitoring, philo) == ERROR)
		return (ERROR);
	ft_join_monitoring_and_philos_threads(table,
		*monitoring, *philo);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_table			table;
	t_philo			*philo;
	t_monitoring	*monitoring;
	int				init_table_and_forks_status;

	if (ft_check_args(argc, argv) == ERROR)
		return (ERROR);
	init_table_and_forks_status = ft_init_table_and_forks(&table, argc, argv);
	if (init_table_and_forks_status == STOP)
		return (SUCCESS);
	if (init_table_and_forks_status == ERROR)
		return (ERROR);
	if (ft_alloc_and_init_monitoring_and_philos(&table,
			&monitoring, &philo) == ERROR)
		return (ERROR);
	table.start_time_in_ms = ft_get_time_in_ms()
		+ (10 * table.number_of_philosophers);
	if (ft_start_simulation(&table, &monitoring, &philo) == ERROR)
		return (ERROR);
	ft_destroy_and_free_all(&table, &monitoring, &philo);
	return (SUCCESS);
}
