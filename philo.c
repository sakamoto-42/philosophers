/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:05:02 by julien            #+#    #+#             */
/*   Updated: 2025/03/25 14:17:03 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_destroy_and_free(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->printf_mutex);
	free(data->forks);
	free(philo);
}

int	main(int argc, char **argv)
{
	t_data			data;
	t_philo			*philo;

	if (ft_check_args(argc, argv) == ERROR)
		return (ERROR);
	if (ft_init_data(&data, argc, argv) == ERROR)
		return (ERROR);
	ft_print_data(&data);
	if (ft_init_philo(&data, &philo) == ERROR)
		return (ERROR);
	ft_destroy_and_free(&data, philo);
	return (SUCCESS);
}
