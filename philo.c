/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:05:02 by julien            #+#    #+#             */
/*   Updated: 2025/03/25 18:38:22 by juduchar         ###   ########.fr       */
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
	//ft_print_data(&data);
	if (ft_init_philo(&data, &philo) == ERROR)
		return (ERROR);
	ft_destroy_and_free(&data, philo);
	return (SUCCESS);
}
