NAME = Phonebook
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
SRC_DIR = src
OBJ_DIR = obj
INCLUDES = -I. -I/usr/include

SRCS = Phonebook.cpp \
	   Contact.cpp \
	   main.cpp

OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
HEADERS = Phonebook.hpp Contact.hpp

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


$(OBJ_DIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re
