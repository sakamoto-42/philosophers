/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_monitoring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:16:10 by julien            #+#    #+#             */
/*   Updated: 2025/03/26 11:48:37 by julien           ###   ########.fr       */
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

void	ft_init_monitoring(t_data *data, t_philo *philo,
	t_monitoring *monitoring)
{
	monitoring->data = data;
	monitoring->philo = philo;
}

int	ft_create_monitoring_thread(t_data *data)
{
	if (pthread_create(&data->monitoring_thread_id, NULL,
			ft_monitoring, (void *)&data) != 0)
	{
		ft_print_error("Error: pthread_create monitoring failed\n");
		return (ERROR);
	}
	return (SUCCESS);
}

int	ft_join_monitoring_thread(t_data *data)
{
	if (pthread_join(data->monitoring_thread_id, NULL) != 0)
	{
		ft_print_error("Error: pthread_join monitoring failed\n");
		return (ERROR);
	}
	return (SUCCESS);
}
