# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/25 00:00:17 by bogoncha          #+#    #+#              #
#    Updated: 2019/04/04 15:32:15 by bogoncha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = src/ft_printf.c src/parser.c src/char_string.c src/numbers.c main.c

OBJS = src/ft_printf.o src/parser.o src/char_string.o src/numbers.o main.o

all: $(NAME)

$(NAME): lib
	$(CC) libft/libft.a $(SRC) -o test

lib: fclean
	make -C libft

clean:
	/bin/rm -rf $(OBJS)
	make -C libft/ clean

fclean: clean
	/bin/rm -rf test
	make -C libft/ fclean

retest: fclean test

re: fclean all
