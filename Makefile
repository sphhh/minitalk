NAME = minitalk

SERVER		= server

CLIENT		= client

SRC_SERVER	= server.c

SRC_CLIENT	= client.c

SERVER_B	= server_bonus

CLIENT_B	= client_bonus

SRC_SERVER_B	= server_bonus.c

SRC_CLIENT_B	= client_bonus.c

CC			= cc

OBJ			= $(SRC:.c=.o)

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

LIBFT_PATH	= libft/libft.a

$(NAME):	libgen
			@$(CC) $(CFLAGS) $(SRC_CLIENT) $(LIBFT_PATH) -o $(CLIENT)
				@$(CC)  $(CFLAGS) $(SRC_SERVER) $(LIBFT_PATH) -o $(SERVER)
					$(info done ✅)

libgen:
			$(info compiling ⌛︎)
			@cd libft && make

all:		$(NAME)

bonus:		libgen
			@$(CC) $(CFLAGS) $(SRC_CLIENT_B) $(LIBFT_PATH) -o $(CLIENT_B)
				@$(CC) $(CFLAGS) $(SRC_SERVER_B) $(LIBFT_PATH) -o $(SERVER_B)
					$(info done ✅)

clean:
			@cd libft && make clean
			$(info Cleaned 🚮)


fclean:
			@$(RM) $(SERVER) $(CLIENT)
			@$(RM) $(SERVER_B) $(CLIENT_B)
			@cd libft && make fclean
			$(info Cleaned 🚮)

re:			fclean all

.PHONY:		all clean fclean re
