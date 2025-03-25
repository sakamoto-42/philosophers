/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:00:46 by julien            #+#    #+#             */
/*   Updated: 2025/03/24 21:51:15 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// memset
# include <string.h>

// printf
# include <stdio.h>

// malloc free
# include <stdlib.h>

// write usleep
# include <unistd.h>

// gettimeofday
# include <sys/time.h>

// pthread_create pthread_detach pthread_join pthread_mutex_init
// pthread_destroy pthread_mutex_lock pthread_mutex_unlock
# include <pthread.h>

// INT_MIN INT_MAX
# include <limits.h>

# define ERROR 1
# define SUCCESS 0
# define NB_ARGS 5
# define COUNT 10000

typedef struct s_data
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
}	t_data;

typedef struct s_philo
{
	int				id;
	pthread_t		thread_id;
	t_data			*data;
}	t_philo;

typedef struct s_counter
{
	unsigned int	count;
	pthread_mutex_t	count_mutex;
}	t_counter;

// debug.c
void	ft_print_data(t_data *data);

// ft_atoi.c
int		ft_atoi(const char *nptr);

// ft_itoa.c
char	*ft_itoa(int n);

// handle_errors.c
void	ft_print_error(char *str);
void	ft_handle_error_msg(int error_nb);

// parsing.c
int		ft_check_args(int argc, char **argv);
int		ft_is_valid_number(const char *str);

// utils.c
size_t	ft_strlen(char *str);
int		ft_isspace(int c);
int		ft_isdigit(int c);

#endif