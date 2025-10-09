#Variables
NAME_CLIENT = client
NAME_SERVER = server
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -f
LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I. -I$(LIBFT_DIR)

#Source and Object Files 
CLIENT_SRCS = client.c minitalk_utils.c
SERVER_SRCS = server.c minitalk_utils.c

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

#Header
HEADERS = minitalk.h $(LIBFT_DIR)/libft.h

#Default Target
all: $(LIBFT) $(NAME_CLIENT) $(NAME_SERVER)

#build LIBFT

$(LIBFT):
	@make -C $(LIBFT_DIR)
 
#Build Rules
$(NAME_CLIENT): $(CLIENT_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -L$(LIBFT_DIR) -lft -o $(NAME_CLIENT)

$(NAME_SERVER): $(SERVER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -L$(LIBFT_DIR) -lft -o $(NAME_SERVER)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

#Utility Targets
clean:
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)
	@make fclean -C $(LIBFT_DIR) 

re: fclean all
