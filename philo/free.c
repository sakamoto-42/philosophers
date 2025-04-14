/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:45:43 by julien            #+#    #+#             */
/*   Updated: 2025/04/12 18:13:21 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_monitoring(t_monitoring **monitoring)
{
	free(*monitoring);
	*monitoring = NULL;
}

void	ft_free_philo(t_philo **philo)
{
	free(*philo);
	*philo = NULL;
}
