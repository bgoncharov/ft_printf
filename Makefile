NAME = libftprintf.a
L_NAME = libft;

FLAGS = -Wall -Werror -Wextra

HEADER = ft_printf.h

SRC = ft_printf.c

OBJS = *.o

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -I$(HEADER) -c $(SRC)

clean:
	/bin/rm/ -f $(OBJS)

fclean:
	/bin/rm -f $(NAME)

re:
	fclean all