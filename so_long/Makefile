
NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBFT_DIR = ./Libft
MLX_DIR = ./mlx_linuxs
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a
INCLUDES = -I. -I$(LIBFT_DIR) -I$(MLX_DIR) -I/usr/include

SRCS = so_long.c \
	so_long_map_utils.c \
	so_long_key.c \
	so_long_utils.c \
	so_long_check.c \
	so_long_character.c 
OBJS = $(SRCS:.c=.o)

HEADERS = so_long.h $(LIBFT_DIR)/libft.h

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)
$(MLX):
	@make -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(INCLUDES) $(LIBFT) -L$(MLX_DIR) -I$(MLX_DIR) -lmlx -lXext -lX11 -o $(NAME)


%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -O3 -c $< -o $@

# 5. Utility Targets
clean:
	$(RM) $(OBJS)
	@make clean -C $(LIBFT_DIR) 
	@make clean -C $(MLX_DIR)

fclean: clean
	$(RM) $(NAME) 
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
