NAME = mini

SERVER		= server

CLIENT		= client

SRC_SERVER	= server.c

SRC_CLIENT	= client.c

CC			= cc

OBJ			= $(SRC:.c=.o)

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

LIBFT_PATH	= libft/libft.a

$(NAME):	libgen $(LIBFT_PATH) $(PRINTF_PATH)
			@$(CC) $(CFLAGS) $(SRC_CLIENT) $(LIBFT_PATH) -o $(CLIENT)
				@$(CC)  $(CFLAGS) $(SRC_SERVER) $(LIBFT_PATH) -o $(SERVER)
					$(info done ✅)

libgen:
			$(info compiling ⌛︎)
			@cd libft && make


all:		$(NAME)

clean:
			@cd libft && make clean
			$(info Cleaned 🚮)


fclean:
			@$(RM) $(SERVER) $(CLIENT)
			@cd libft && make fclean
			$(info Cleaned 🚮)

re:			fclean all

.PHONY:		all clean fclean re
