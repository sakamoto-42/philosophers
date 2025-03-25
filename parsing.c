/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:33:05 by julien            #+#    #+#             */
/*   Updated: 2025/03/24 16:16:27 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_is_valid_number(argv[i])
			|| ((i >= 1 && i <= 4 && ft_atoi(argv[i]) <= 0)
				|| (i == 5 && ft_atoi(argv[i]) < 0)))
		{
			ft_handle_error_msg(i);
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int	ft_is_valid_number(const char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
