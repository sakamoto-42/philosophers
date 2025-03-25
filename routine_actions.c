/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:44:55 by juduchar          #+#    #+#             */
/*   Updated: 2025/03/25 17:35:18 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	ft_lock_forks(philo);
	ft_print_info(philo, "is eating \n");
	usleep(philo->data->time_to_eat * 1000);
	philo->meals_eaten++;
	ft_unlock_forks(philo);
}

void	ft_sleep(t_philo *philo)
{
	ft_print_info(philo, "is sleeping\n");
	usleep(philo->data->time_to_sleep * 1000);
}
void	ft_think(t_philo *philo)
{
	ft_print_info(philo, "is thinking\n");
}