
NAME = BraiiiiiiinnnzzzZ
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
OBJ_DIR = obj

SRCS = newZombie.cpp \
		randomChump.cpp \
		Zombie.cpp \
		main.cpp
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
