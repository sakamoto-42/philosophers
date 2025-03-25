/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:00:58 by julien            #+#    #+#             */
/*   Updated: 2025/03/25 17:36:01 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_philo(t_data *data, t_philo **philo)
{
	if (ft_alloc_philo(data, philo) == ERROR)
		return (ERROR);
	if (ft_create_philo_threads(data, *philo) == ERROR)
		return (ERROR);
	if (ft_join_philo_threads(data, *philo) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	ft_alloc_philo(t_data *data, t_philo **philo)
{
	*philo = malloc(data->number_of_philosophers * sizeof(t_philo));
	if (!*philo)
	{
		ft_print_error("Error: malloc failed\n");
		return (ERROR);
	}
	memset(*philo, 0, data->number_of_philosophers * sizeof(t_philo));
	return (SUCCESS);
}

void	ft_set_forks(t_philo *philo, int i, int number_of_philosophers)
{
	int	right_philo_index;

	right_philo_index = (i + 1) % number_of_philosophers;
	philo[i].left_fork = &philo->data->forks[i];
	philo[i].right_fork = &philo->data->forks[right_philo_index];
}

int	ft_create_philo_threads(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		philo[i].id = i + 1;
		if (pthread_create(&philo[i].thread_id, NULL,
				ft_philo_routine, (void *)&philo[i]) != 0)
		{
			ft_print_error("Error: pthread_create ");
			ft_print_error(ft_itoa(i + 1));
			ft_print_error(" failed\n");
			return (ERROR);
		}
		philo[i].data = data;
		ft_set_forks(philo, i, data->number_of_philosophers);
		philo[i].meals_eaten = 0;
		i++;
	}
	return (SUCCESS);
}

int	ft_join_philo_threads(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_join(philo[i].thread_id, NULL) != 0)
		{
			ft_print_error("Error: pthread_join ");
			ft_print_error(ft_itoa(i + 1));
			ft_print_error(" failed\n");
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}
