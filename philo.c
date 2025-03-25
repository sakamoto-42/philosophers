/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:05:02 by julien            #+#    #+#             */
/*   Updated: 2025/03/25 14:25:42 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
