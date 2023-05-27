SERVER_SRCS	=	server.c

SERVER_OBJS	=	$(SERVER_SRCS:.c=.o)

SERVER_NAME	=	server

CLIENT_SRCS	=	client.c

CLIENT_OBJS	=	$(CLIENT_SRCS:.c=.o)

CLIENT_NAME	=	client

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

all: $(SERVER_NAME) $(CLIENT_NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I ./libft

$(SERVER_NAME):	$(SERVER_OBJS)
	@make -C ./libft
	$(CC) $(CFLAGS) $(SERVER_OBJS) -o $(SERVER_NAME) libft/libft.a

$(CLIENT_NAME): $(CLIENT_OBJS)
	@make -C ./libft
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(CLIENT_NAME) libft/libft.a

clean:
	@cd libft && make clean
	@$(RM) $(SERVER_OBJS)
	@$(RM) $(CLIENT_OBJS)

fclean: clean
	@cd libft && make fclean
	@$(RM) $(SERVER_NAME)
	@$(RM) $(CLIENT_NAME)
	@echo "$(SERVER_NAME) deleted"
	@echo "$(CLIENT_NAME) deleted"

re: fclean all

.PHONY: all clean fclean re