# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/25 00:00:17 by bogoncha          #+#    #+#              #
#    Updated: 2019/04/23 18:36:24 by bogoncha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = src/ft_printf.c src/parser.c src/flg_scpercent.c src/flg_int.c main.c \
	src/flg_pointer.c src/flg_uint.c src/flg_bin.c \
	src/flg_hex.c src/flg_oct.c src/flg_float.c src/flg_unicode.c src/flg_scientific.c \
	src/make_list.c

OBJS = src/ft_printf.o src/parser.o src/flg_scpercent.o src/flg_int.o main.o \
	src/flg_pointer.o src/flg_uint.o src/flg_bin.o \
	src/flg_hex.o src/flg_oct.o src/flg_oct.o src/flg_unicode.o src/flg_scientific.o \
	src/make_list.o

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
