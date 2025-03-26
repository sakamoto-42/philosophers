/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_monitoring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:16:10 by julien            #+#    #+#             */
/*   Updated: 2025/03/26 16:16:53 by juduchar         ###   ########.fr       */
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

int	ft_init_monitoring(t_data *data, t_philo *philo,
	t_monitoring *monitoring)
{
	monitoring->data = data;
	monitoring->philo = philo;
	monitoring->simulation_finished = 0;
	if (pthread_mutex_init(&monitoring->simulation_finished_mutex, NULL) != 0)
		return (ERROR);
	return (SUCCESS);
}

int	ft_create_monitoring_thread(t_monitoring *monitoring)
{
	if (pthread_create(&monitoring->thread_id, NULL,
			ft_monitoring, (void *)monitoring) != 0)
	{
		ft_print_error("Error: pthread_create monitoring failed\n");
		return (ERROR);
	}
	return (SUCCESS);
}

int	ft_join_monitoring_thread(t_monitoring *monitoring)
{
	if (pthread_join(monitoring->thread_id, NULL) != 0)
	{
		ft_print_error("Error: pthread_join monitoring failed\n");
		return (ERROR);
	}
	return (SUCCESS);
}
