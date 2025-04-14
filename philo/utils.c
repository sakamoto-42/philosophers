/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:31:59 by julien            #+#    #+#             */
/*   Updated: 2025/04/14 22:35:55 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

long	ft_get_time_in_ms(void)
{
	struct timeval	time;
	long			timestamp_in_ms;

	gettimeofday(&time, NULL);
	timestamp_in_ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (timestamp_in_ms);
}

void	ft_usleep_interruptible(t_table *table, t_monitoring *monitoring,
	long time_to_usleep_in_ms)
{
	long	start;
	long	now;

	start = ft_get_time_in_ms();
	now = start;
	while (now - start < time_to_usleep_in_ms)
	{
		if (ft_mutex_is_simulation_finished(monitoring))
			break ;
		usleep(table->number_of_philosophers);
		now = ft_get_time_in_ms();
	}
}
