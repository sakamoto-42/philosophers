/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:53:24 by juduchar          #+#    #+#             */
/*   Updated: 2025/03/26 11:23:16 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_all_philos_ate_enough(t_data *data)
{
	//int	i;

	//i = 0;
	(void)data;
	return (1);
}



void	*ft_monitoring(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	while (!ft_mutex_is_simulation_finished(data))
	{
		pthread_mutex_lock(&data->printf_mutex);
		data->simulation_finished = ft_check_all_philos_ate_enough(data);
		pthread_mutex_unlock(&data->printf_mutex);
		
		//pthread_mutex_lock(&data->printf_mutex);
		//printf("I WATCH\n");
		//pthread_mutex_unlock(&data->printf_mutex);
		usleep(1000 * 1000);
	}
	return (NULL);
}

