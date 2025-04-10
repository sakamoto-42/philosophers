/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:45:38 by juduchar          #+#    #+#             */
/*   Updated: 2025/04/10 15:10:06 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_mutex_lock_forks(t_table *table,
	t_monitoring *monitoring, t_philo *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	if (philo->id % 2 == 0)
	{
		first_fork = philo->left_fork;
		second_fork = philo->right_fork;
	}
	else
	{
		first_fork = philo->right_fork;
		second_fork = philo->left_fork;
	}
	pthread_mutex_lock(first_fork);
	ft_print_info(table, monitoring, philo, "has taken a fork\n");
	pthread_mutex_lock(second_fork);
	ft_print_info(table, monitoring, philo, "has taken a fork\n");
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
