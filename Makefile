NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -pthread

SRCS_FILES = \
	debug.c \
	destroy_and_free.c \
	ft_atoi.c \
	ft_itoa.c \
	handle_errors.c \
	init_data.c \
	init_philo.c \
	init_monitoring.c \
	init_philo_and_monitoring.c \
	monitoring.c \
	mutex_utils.c \
	parsing.c \
	philo.c \
	routine.c \
	routine_actions.c \
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
