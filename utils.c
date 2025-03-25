/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:31:59 by julien            #+#    #+#             */
/*   Updated: 2025/03/25 10:19:27 by julien           ###   ########.fr       */
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
