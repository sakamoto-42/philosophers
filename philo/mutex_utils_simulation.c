/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils_simulation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:50:07 by julien            #+#    #+#             */
/*   Updated: 2025/04/13 12:50:29 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_mutex_set_simulation_finished(t_monitoring *monitoring,
	int is_finished)
{
	pthread_mutex_lock(&monitoring->simulation_finished_mutex);
	monitoring->simulation_finished = is_finished;
	if (is_finished == 1)
		usleep(100);
	pthread_mutex_unlock(&monitoring->simulation_finished_mutex);
}

int	ft_mutex_is_simulation_finished(t_monitoring *monitoring)
{
	int	result;

	pthread_mutex_lock(&monitoring->simulation_finished_mutex);
	result = monitoring->simulation_finished;
	pthread_mutex_unlock(&monitoring->simulation_finished_mutex);
	return (result);
}
