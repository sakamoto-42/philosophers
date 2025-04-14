/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:10:24 by julien            #+#    #+#             */
/*   Updated: 2025/03/20 21:57:38 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	handle_overflow(long long result, int digit, int sign)
{
	if ((result > (INT_MAX / 10))
		|| (result == (INT_MAX / 10)
			&& (digit > INT_MAX % 10)))
	{
		if (sign == 1)
			return (INT_MAX);
		else
			return (INT_MIN);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	long long	result;
	int			sign;
	int			overflow;

	result = 0;
	sign = 1;
	while (ft_isspace((int)*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit((int)*nptr))
	{
		overflow = handle_overflow(result, (*nptr - '0'), sign);
		if (overflow)
			return (overflow);
		result = (result * 10) + (*nptr - '0');
		nptr++;
	}
	return ((int)(sign * result));
}
