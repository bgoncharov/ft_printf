# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/25 00:00:17 by bogoncha          #+#    #+#              #
#    Updated: 2019/04/07 20:32:48 by bogoncha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = src/ft_printf.c src/parser.c src/flg_scpercent.c src/flg_int.c main.c \
	src/flg_box.c src/flg_pointer.c src/flg_u.c

OBJS = src/ft_printf.o src/parser.o src/flg_scpercent.o src/flg_int.o main.o \
	src/flg_box.o src/flg_pointer.o src/flg_u.o

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
