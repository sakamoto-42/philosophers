/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:45:38 by juduchar          #+#    #+#             */
/*   Updated: 2025/03/27 14:44:11 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_mutex_lock_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		usleep(100);
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

int	ft_mutex_is_simulation_finished(t_monitoring *monitoring)
{
	int	result;

	pthread_mutex_lock(&monitoring->simulation_finished_mutex);
	result = monitoring->simulation_finished;
	pthread_mutex_unlock(&monitoring->simulation_finished_mutex);
	return (result);
}
