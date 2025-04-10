/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:00:46 by julien            #+#    #+#             */
/*   Updated: 2025/04/10 15:14:41 by julien           ###   ########.fr       */
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
# define MAX_PHILOS 200

typedef struct s_philo		t_philo;
typedef struct s_monitoring	t_monitoring;

typedef struct s_table
{
	unsigned long	start_time_in_ms;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_required;
	pthread_mutex_t	printf_mutex;
	pthread_mutex_t	*forks;
}	t_table;

typedef struct s_monitoring
{
	pthread_t		thread_id;
	t_table			*table;
	t_philo			*philo;
	int				simulation_finished;
	pthread_mutex_t	simulation_finished_mutex;
}	t_monitoring;

typedef struct s_philo
{
	pthread_t		thread_id;
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				meals_eaten;
	pthread_mutex_t	meals_eaten_mutex;
	long			last_meal_time;
	pthread_mutex_t	last_meal_time_mutex;
	t_monitoring	*monitoring;
}	t_philo;

// debug.c
void	ft_print_table(t_table *table);

// parsing.c
int		ft_check_args(int argc, char **argv);

// ft_atoi.c
int		ft_atoi(const char *nptr);

// handle_errors.c
void	ft_handle_error_msg(int error_nb);
void	ft_print_error(char *str);

// ft_itoa.c
char	*ft_itoa(int n);

// init_table.c
int		ft_init_table(t_table *table, int argc, char **argv);

// alloc_init.c
int		ft_alloc_and_init_monitoring_and_philos(t_table *table,
			t_monitoring **monitoring, t_philo **philo);

// alloc_init_monitoring.c
int		ft_alloc_monitoring(t_monitoring **monitoring);
int		ft_init_monitoring(t_table *table,
			t_monitoring *monitoring, t_philo *philo);

// alloc_init_philos.c
int		ft_alloc_philos(t_table *table, t_philo **philo);
int		ft_init_philos(t_table *table,
			t_monitoring *monitoring, t_philo *philo);

// create_threads.c
int		ft_create_monitoring_and_philos_threads(t_table *table,
			t_monitoring *monitoring, t_philo *philo);

// monitoring.c
void	*ft_monitoring(void *param);

// routine.c
void	*ft_philo_routine(void *param);

// routine_actions.c
void	ft_eat(t_table *table, t_monitoring *monitoring, t_philo *philo);
void	ft_sleep(t_table *table, t_monitoring *monitoring, t_philo *philo);
void	ft_think(t_table *table, t_monitoring *monitoring, t_philo *philo);

// print_info.c
void	ft_print_info(t_table *table,
			t_monitoring *monitoring, t_philo *philo, char *str);

// mutex_utils.c
void	ft_mutex_lock_forks(t_table *table,
			t_monitoring *monitoring, t_philo *philo);
void	ft_mutex_unlock_forks(t_philo *philo);
int		ft_mutex_is_simulation_finished(t_monitoring *monitoring);

// join_threads.c
int		ft_join_monitoring_and_philos_threads(t_table *table,
			t_monitoring *monitoring, t_philo *philo);

// destroy_and_free.c
void			ft_destroy_and_free(t_table *table,
					t_monitoring *s_monitoring, t_philo *philo);

// utils.c
size_t			ft_strlen(char *str);
int				ft_isspace(int c);
int				ft_isdigit(int c);
unsigned long	ft_get_time_in_ms(void);
void			ft_usleep_interruptible(long time_to_usleep_in_ms,
					t_philo *philo);

#endif