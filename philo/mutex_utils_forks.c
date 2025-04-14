/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils_forks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:00:42 by julien            #+#    #+#             */
/*   Updated: 2025/04/12 16:06:34 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_mutex_lock_one_fork(t_table *table, t_monitoring *monitoring,
	t_philo *philo, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	ft_print_info(table, monitoring, philo, "has taken a fork\n");
}

void	ft_mutex_lock_two_forks(t_table *table,
t_monitoring *monitoring, t_philo *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	if (philo->left_fork < philo->right_fork)
	{
		first_fork = philo->left_fork;
		second_fork = philo->right_fork;
	}
	else
	{
		first_fork = philo->right_fork;
		second_fork = philo->left_fork;
	}
	ft_mutex_lock_one_fork(table, monitoring, philo, first_fork);
	ft_mutex_lock_one_fork(table, monitoring, philo, second_fork);
}

void	ft_mutex_unlock_one_fork(pthread_mutex_t *fork)
{
	pthread_mutex_unlock(fork);
}

void	ft_mutex_unlock_two_forks(t_philo *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	if (philo->left_fork < philo->right_fork)
	{
		first_fork = philo->left_fork;
		second_fork = philo->right_fork;
	}
	else
	{
		first_fork = philo->right_fork;
		second_fork = philo->left_fork;
	}
	ft_mutex_unlock_one_fork(second_fork);
	ft_mutex_unlock_one_fork(first_fork);
}
