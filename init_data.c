/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:00:45 by julien            #+#    #+#             */
/*   Updated: 2025/03/25 14:20:52 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_data(t_data *data, int argc, char **argv)
{
	data->start_time_in_ms = ft_get_time_in_ms();
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc - 1 == NB_ARGS)
		data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		data->number_of_times_each_philosopher_must_eat = 0;
	if (pthread_mutex_init(&data->printf_mutex, NULL) != 0)
		return (ERROR);
	if (ft_init_forks(data) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	ft_init_forks(t_data *data)
{
	int	i;

	data->forks = malloc(data->number_of_philosophers
			* sizeof(pthread_mutex_t));
	if (!data->forks)
		return (ERROR);
	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
