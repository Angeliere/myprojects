
NAME = Philosophers
CC = cc
CFLAGS = -Wall -Wextra -Werror -g 
RM = rm -f
SRC_DIR = src
OBJ_DIR = obj
INCLUDES = -I. -I/usr/include

SRCS =	philosophers.c \
		philosophers_mutex_lock.c \
		philosophers_action.c \
		utility_func.c	\
		dead_monitoring.c

SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRCS)) 
OBJS = $(SRC_FILES:.c=.o)
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(OBJS))

HEADERS = philosophers.h

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@make clean -C

fclean: clean
	$(RM) $(NAME) 
	@make fclean -C

re: fclean all

.PHONY: all clean fclean re
