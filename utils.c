/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:31:59 by julien            #+#    #+#             */
/*   Updated: 2025/03/27 15:26:28 by juduchar         ###   ########.fr       */
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

void	ft_usleep_interruptible(long time_to_usleep_in_ms, t_philo *philo)
{
	long	start;
	long	now;
	int		finished;

	start = ft_get_time_in_ms();
	now = start;
	finished = 0;
	while (now - start < time_to_usleep_in_ms && !finished)
	{
		usleep(500);
		now = ft_get_time_in_ms();
		finished = ft_mutex_is_simulation_finished(philo->monitoring);
	}
}