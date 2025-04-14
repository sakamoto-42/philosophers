/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:00:46 by julien            #+#    #+#             */
/*   Updated: 2025/04/14 22:45:57 by julien           ###   ########.fr       */
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

# define ERROR		1
# define SUCCESS	0
# define STOP		2
# define NB_ARGS 	5

typedef struct s_philo		t_philo;
typedef struct s_monitoring	t_monitoring;

typedef struct s_table
{
	long			start_time_in_ms;
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

// parsing.c
int		ft_check_args(int argc, char **argv);

// ft_atoi.c
int		ft_atoi(const char *nptr);

// handle_errors.c
void	ft_handle_error_msg(int error_nb);
void	ft_print_error(char *str);

// ft_itoa.c
char	*ft_itoa(int n);

// init_table_and_forks.c
int		ft_init_table_and_forks(t_table *table, int argc, char **argv);

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
			t_monitoring **monitoring, t_philo **philo);

// monitoring.c
void	*ft_monitoring(void *param);

// philo_routine.c
void	*ft_philo_routine(void *param);

// philo_routine_actions.c
void	ft_eat(t_table *table, t_monitoring *monitoring, t_philo *philo);
void	ft_sleep(t_table *table, t_monitoring *monitoring, t_philo *philo);
void	ft_think(t_table *table, t_monitoring *monitoring,
			t_philo *philo);

// print_info.c
void	ft_print_info(t_table *table,
			t_monitoring *monitoring, t_philo *philo, char *str);

// join_threads.c
void	ft_join_monitoring_and_philos_threads(t_table *table,
			t_monitoring *monitoring, t_philo *philo);

// destroy_and_free.c
void	ft_destroy_and_free_table(t_table *table);
void	ft_destroy_and_free_monitoring(t_monitoring **monitoring);
void	ft_destroy_and_free_philos(t_table *table, t_philo **philo);
void	ft_destroy_and_free_all(t_table *table,
			t_monitoring **monitoring, t_philo **philo);

// free.c
void	ft_free_monitoring(t_monitoring **monitoring);
void	ft_free_philo(t_philo **philo);

// mutex_utils.c
long	ft_mutex_get_last_meal_time(t_philo *philo);
void	ft_mutex_set_last_meal_time(t_philo *philo, long last_meal_time);
void	ft_mutex_increment_meals_eaten(t_philo *philo);
long	ft_mutex_compute_time_to_think(t_table *table, t_philo *philo);

// mutex_utils_simulation.c
void	ft_mutex_set_simulation_finished(t_monitoring *monitoring,
			int is_finished);
int		ft_mutex_is_simulation_finished(t_monitoring *monitoring);

// mutex_utils_forks.c
void	ft_mutex_lock_one_fork(t_table *table, t_monitoring *monitoring,
			t_philo *philo, pthread_mutex_t *fork);
void	ft_mutex_lock_two_forks(t_table *table,
			t_monitoring *monitoring, t_philo *philo);
void	ft_mutex_unlock_one_fork(pthread_mutex_t *fork);
void	ft_mutex_unlock_two_forks(t_philo *philo);

// utils.c
size_t	ft_strlen(char *str);
int		ft_isspace(int c);
int		ft_isdigit(int c);
long	ft_get_time_in_ms(void);
void	ft_usleep_interruptible(t_table *table, t_monitoring *monitoring,
			long time_to_usleep_in_ms);

#endif