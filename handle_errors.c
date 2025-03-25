/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:34:41 by julien            #+#    #+#             */
/*   Updated: 2025/03/24 21:33:37 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_error(char *str)
{
	write(2, str, ft_strlen(str));
}

void	ft_handle_error_msg(int error_nb)
{
	if (error_nb == 1)
		ft_print_error("number_of_philosophers must be a positive integer\n");
	else if (error_nb == 2)
		ft_print_error("time_to_die must be a positive integer\n");
	else if (error_nb == 3)
		ft_print_error("time_to_eat must be a positive integer\n");
	else if (error_nb == 4)
		ft_print_error("time_to_sleep must be a positive integer\n");
	else if (error_nb == 5)
	{
		ft_print_error("number_of_times_each_philosopher_must_eat");
		ft_print_error(" must be a positive integer\n");
	}
}
