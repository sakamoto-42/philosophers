/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_and_monitoring.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:20:06 by juduchar          #+#    #+#             */
/*   Updated: 2025/03/26 21:37:32 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_philo_and_monitoring(t_data *data,
	t_philo **philo, t_monitoring **monitoring)
{
	if (ft_alloc_philo(data, philo) == ERROR)
		return (ERROR);
	if (ft_init_philo(data, *philo) == ERROR)
		return (ERROR);
	if (ft_alloc_monitoring(monitoring) == ERROR)
		return (ERROR);
	if (ft_init_monitoring(data, *philo, *monitoring) == ERROR)
		return (ERROR);
	ft_link_monitoring_to_philo(data, *philo, *monitoring);
	if (ft_create_philo_threads(data, *philo) == ERROR)
		return (ERROR);
	if (ft_create_monitoring_thread(*monitoring) == ERROR)
		return (ERROR);
	if (ft_join_philo_threads(data, *philo) == ERROR)
		return (ERROR);
	if (ft_join_monitoring_thread(*monitoring) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

void	ft_link_monitoring_to_philo(t_data *data, t_philo *philo,
		t_monitoring *monitoring)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		philo[i].monitoring = monitoring;
		i++;
	}
}
