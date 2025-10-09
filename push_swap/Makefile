
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -f
SRC_DIR = src
LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I. -I$(LIBFT_DIR) -I/usr/include

SRCS = push_swap.c \
	push_swap_utils.c \
	mouvement_operation.c \
	mouvement_operation2.c \
	push_swap_find.c \
	rotation.c \
	sorting.c \
	sortingbis.c \
	validation.c \
    parsing.c \
	parsing_utils.c \
	mouvement_utils.c \
	parse_number_utils.c \
	sortingbis_utils.c \
	sortingbis_push_utils.c \
	sorting_utils.c
SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRCS)) 
OBJS = $(SRC_FILES:.c=.o)

HEADERS = push_swap.h $(LIBFT_DIR)/libft.h

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBFT) -o $(NAME)


$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@make clean -C $(LIBFT_DIR) 

fclean: clean
	$(RM) $(NAME) 
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
