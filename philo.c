/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:05:02 by julien            #+#    #+#             */
/*   Updated: 2025/03/24 22:15:47 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo_routine(void *param)
{
	t_philo			*philo;
	//t_counter		*counter;
	//unsigned int	i;

	//counter = (t_counter *)data;
	//pthread_mutex_lock(&counter->count_mutex);
	philo = (t_philo *)param;
	printf("philo %d\n", philo->id);
	printf("I sleep: %d ms\n", philo->data->time_to_sleep);
	usleep(philo->data->time_to_sleep);
	printf("I eat: %d ms\n", philo->data->time_to_eat);
	usleep(philo->data->time_to_eat);
	//printf("I think: %d ms\n", philo->data->time_to_think);
	//printf("compte au depart : %u\n", counter->count);
	//pthread_mutex_unlock(&counter->count_mutex);
	//i = 0;
	//while (i < COUNT)
	//{
	//	pthread_mutex_lock(&counter->count_mutex);
	//	counter->count++;
	//	pthread_mutex_unlock(&counter->count_mutex);
	//	i++;
	//}
	//pthread_mutex_lock(&counter->count_mutex);
	//printf("compte a la fin : %u\n", counter->count);
	//pthread_mutex_unlock(&counter->count_mutex);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data			data;
	int				error;
	t_philo			*philo;
	//t_counter		counter;
	int				i;

	if (!(argc - 1 >= 4 && argc - 1 <= NB_ARGS))
	{
		ft_print_error("Error: wrong number of arguments\n");
		ft_print_error("Usage: ./philo number_of_philosophers time_to_die ");
		ft_print_error("time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return (ERROR);
	}
	error = ft_check_args(argc, argv);
	if (error == ERROR)
		return (ERROR);
	data.number_of_philosophers = ft_atoi(argv[1]);
	data.time_to_die = ft_atoi(argv[2]);
	data.time_to_eat = ft_atoi(argv[3]);
	data.time_to_sleep = ft_atoi(argv[4]);
	if (argc - 1 == NB_ARGS)
		data.number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		data.number_of_times_each_philosopher_must_eat = 0;
	ft_print_data(&data);
	//counter.count = 0;
	//pthread_mutex_init(&counter.count_mutex, NULL);
	//printf("Main : le compte attendu est de %u\n", data.number_of_philosophers * COUNT);
	philo = malloc(data.number_of_philosophers * sizeof(t_philo));
	if (!philo)
	{
		ft_print_error("Error: malloc failed\n");
		return (ERROR);
	}
	memset(philo, 0, data.number_of_philosophers * sizeof(t_philo));
	i = 0;
	while (i < data.number_of_philosophers)
	{
		philo[i].id = i + 1;
		philo[i].data = &data;
		if (pthread_create(&philo[i].thread_id, NULL, ft_philo_routine, (void *)&philo[i]) != 0)
		{
			ft_print_error("Error: pthread_create ");
			ft_print_error(ft_itoa(i + 1));
			ft_print_error(" failed\n");
			return (ERROR);
		}
		printf("thread %d created\n", i + 1);
		if (pthread_join(philo[i].thread_id, NULL) != 0)
		{
			ft_print_error("Error: pthread_join ");
			ft_print_error(ft_itoa(i + 1));
			ft_print_error(" failed\n");
			return (ERROR);
		}
		printf("thread %d joined\n", i + 1);
		i++;
	}
	//printf("%u\n", counter.count);
	//pthread_mutex_destroy(&counter.count_mutex);
	return (SUCCESS);
}
