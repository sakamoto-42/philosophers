NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -pthread

SRCS_FILES = \
	alloc_init_monitoring.c \
	alloc_init_philos.c \
	alloc_init.c \
	create_threads.c \
	destroy_and_free.c \
	free.c \
	ft_atoi.c \
	ft_itoa.c \
	handle_errors.c \
	init_table_and_forks.c \
	join_threads.c \
	monitoring.c \
	mutex_utils_forks.c \
	mutex_utils_simulation.c \
	mutex_utils.c \
	parsing.c \
	philo_routine_actions.c \
	philo_routine.c \
	philo.c \
	print_info.c \
	utils.c \

OBJS = $(SRCS_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re