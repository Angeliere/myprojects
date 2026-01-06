
NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -pthread
RM = rm -f
SRC_DIR = src
OBJ_DIR = obj
INCLUDES = -I. -I/usr/include

SRCS =	philosophers.c \
		philosophers_mutex_lock.c \
		philosophers_actions.c \
		utility_func.c	\
		dead_monitoring.c \
		pthread_creation_util.c 

SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRCS)) 
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

HEADERS = philosophers.h

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re
