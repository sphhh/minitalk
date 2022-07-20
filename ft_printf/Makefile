NAME		= libftprintf.a

SRC			= ft_printf.c ft_putchar_print.c ft_putstr_print.c ft_putnbr_print.c\
			  ft_putunbr_print.c ft_hex_print.c ft_pointeraddress_print.c

OBJ			= $(SRC:.c=.o)

CC			= cc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -c $(SRC)
				ar rcs $(NAME) $(OBJ)

all:		$(NAME)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
