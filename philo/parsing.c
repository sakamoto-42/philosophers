/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:33:05 by julien            #+#    #+#             */
/*   Updated: 2025/04/10 18:53:52 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_args_number(int argc)
{
	if (!(argc - 1 >= 4 && argc - 1 <= NB_ARGS))
	{
		ft_print_error("Error: wrong number of arguments\n");
		ft_print_error("Usage: ./philo number_of_philosophers time_to_die ");
		ft_print_error("time_to_eat time_to_sleep ");
		ft_print_error("[number_of_times_each_philosopher_must_eat]\n");
		return (ERROR);
	}
	return (SUCCESS);
}

static int	ft_is_valid_number(const char *str)
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

static int	ft_check_args_valid(int argc, char **argv)
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

int	ft_check_args(int argc, char **argv)
{
	if (ft_check_args_number(argc) == ERROR)
		return (ERROR);
	if (ft_check_args_valid(argc, argv) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
