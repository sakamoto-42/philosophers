/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:05:02 by julien            #+#    #+#             */
/*   Updated: 2025/03/26 11:46:56 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_philo_and_monitoring(t_data *data,
	t_philo **philo, t_monitoring **monitoring)
{
	if (ft_alloc_philo(data, philo) == ERROR)
		return (ERROR);
	ft_init_philo(data, *philo);
	if (ft_create_philo_threads(data, *philo) == ERROR)
		return (ERROR);
	if (ft_alloc_monitoring(monitoring) == ERROR)
		return (ERROR);
	ft_init_monitoring(data, *philo, *monitoring);
	if (ft_create_monitoring_thread(data) == ERROR)
		return (ERROR);
	if (ft_join_philo_threads(data, *philo) == ERROR)
		return (ERROR);
	if (ft_join_monitoring_thread(data) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data			data;
	t_philo			*philo;
	t_monitoring	*monitoring;

	if (ft_check_args(argc, argv) == ERROR)
		return (ERROR);
	if (ft_init_data(&data, argc, argv) == ERROR)
		return (ERROR);
	//ft_print_data(&data);
	if (ft_init_philo_and_monitoring(&data, &philo,
			&monitoring) == ERROR)
		return (ERROR);
	ft_destroy_and_free(&data, philo);
	return (SUCCESS);
}
