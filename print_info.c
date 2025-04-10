/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:55:56 by julien            #+#    #+#             */
/*   Updated: 2025/04/10 14:56:18 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_info(t_table *table, t_monitoring *monitoring,
	t_philo *philo, char *str)
{
	long	timestamp_in_ms;

	if (ft_mutex_is_simulation_finished(monitoring))
		return ;
	timestamp_in_ms = ft_get_time_in_ms() - table->start_time_in_ms;
	pthread_mutex_lock(&table->printf_mutex);
	printf("%lu %d %s", timestamp_in_ms, philo->id, str);
	pthread_mutex_unlock(&table->printf_mutex);
}