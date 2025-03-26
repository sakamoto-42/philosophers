/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:44:48 by julien            #+#    #+#             */
/*   Updated: 2025/03/26 15:38:31 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_data(t_data *data)
{
	printf("start_time_in_ms: %ld\n", data->start_time_in_ms);
	printf("number_of_philosophers: %d\n", data->number_of_philosophers);
	printf("time_to_die: %d\n", data->time_to_die);
	printf("time_to_eat: %d\n", data->time_to_eat);
	printf("time_to_sleep: %d\n", data->time_to_sleep);
	printf("number_of_times_each_philosopher_must_eat: %d\n",
		data->meals_required);
}
