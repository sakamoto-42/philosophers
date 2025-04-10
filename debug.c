/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:44:48 by julien            #+#    #+#             */
/*   Updated: 2025/04/10 15:52:14 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_table(t_table *table)
{
	printf("start_time_in_ms: %ld\n", table->start_time_in_ms);
	printf("number_of_philosophers: %d\n", table->number_of_philosophers);
	printf("time_to_die: %d\n", table->time_to_die);
	printf("time_to_eat: %d\n", table->time_to_eat);
	printf("time_to_sleep: %d\n", table->time_to_sleep);
	printf("number_of_times_each_philosopher_must_eat: %d\n",
		table->meals_required);
}
