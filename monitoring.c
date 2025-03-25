/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:53:24 by juduchar          #+#    #+#             */
/*   Updated: 2025/03/25 18:21:35 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_monitoring(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	while (1)
	{
		pthread_mutex_lock(&data->printf_mutex);
		printf("I WATCH\n");
		pthread_mutex_unlock(&data->printf_mutex);
		usleep(400 * 1000);
	}	
	return (NULL);
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