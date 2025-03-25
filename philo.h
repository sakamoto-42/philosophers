/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:00:46 by julien            #+#    #+#             */
/*   Updated: 2025/03/25 14:26:11 by julien           ###   ########.fr       */
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
	long			start_time_in_ms;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	pthread_mutex_t	printf_mutex;
	pthread_mutex_t	*forks;
}	t_data;

typedef struct s_philo
{
	int				id;
	pthread_t		thread_id;
	t_data			*data;
}	t_philo;

// debug.c
void	ft_print_data(t_data *data);

// destroy_and_free.c
void	ft_destroy_and_free(t_data *data, t_philo *philo);

// ft_atoi.c
int		ft_atoi(const char *nptr);

// ft_itoa.c
char	*ft_itoa(int n);

// handle_errors.c
void	ft_print_error(char *str);
void	ft_handle_error_msg(int error_nb);

// parsing.c
int		ft_check_args(int argc, char **argv);
int		ft_check_args_number(int argc);
int		ft_check_args_valid(int argc, char **argv);

// init_data.c
int		ft_init_data(t_data *data, int argc, char **argv);
int		ft_init_forks(t_data *data);
int		ft_init_philo(t_data *data, t_philo **philo);
int		ft_alloc_philo(t_data *data, t_philo **philo);
int		ft_create_philo_threads(t_data *data, t_philo *philo);
int		ft_join_philo_threads(t_data *data, t_philo *philo);

// routine.c
void	*ft_philo_routine(void *param);
void	ft_print_info(t_philo *philo, char *str);

// utils.c
size_t	ft_strlen(char *str);
int		ft_isspace(int c);
int		ft_isdigit(int c);
long	ft_get_time_in_ms(void);

#endif