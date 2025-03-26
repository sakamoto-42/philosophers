/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:45:38 by juduchar          #+#    #+#             */
/*   Updated: 2025/03/26 10:59:00 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_mutex_lock_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		ft_print_info(philo, "has taken a fork\n");
		pthread_mutex_lock(philo->right_fork);
		ft_print_info(philo, "has taken a fork\n");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		ft_print_info(philo, "has taken a fork\n");
		pthread_mutex_lock(philo->left_fork);
		ft_print_info(philo, "has taken a fork\n");
	}
}

void	ft_mutex_unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

int	ft_mutex_is_simulation_finished(t_data *data)
{
	int	result;

	pthread_mutex_lock(&data->simulation_finished_mutex);
	result = data->simulation_finished;
	pthread_mutex_unlock(&data->simulation_finished_mutex);
	return (result);
}
