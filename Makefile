# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/25 00:00:17 by bogoncha          #+#    #+#              #
#    Updated: 2019/04/01 16:20:42 by bogoncha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = src/ft_printf.c src/parser.c src/char_string.c src/numbers.c main.c

OBJS = src/ft_printf.o src/parser.o src/char_string.o src/numbers.o main.o

all: $(NAME)

test: $(NAME)
	@echo "\x1b[92;4mTest file compiled .....\x1b[0m"

$(NAME): lib
	@gcc libft/libft.a $(SRC) -o test

lib:
	@make -C libft
	@echo "\x1b[92;4mLibft compiled ....\x1b[0m"

clean:
	@/bin/rm -rf $(OBJS)
	@make -C libft/ clean
	@echo "\x1b[91;4mObjects cleaned ..\x1b[0m"

fclean: clean
	@/bin/rm -rf test
	@make -C libft/ fclean
	@echo "\x1b[91;4mLibrary cleaned ...\x1b[0m"

retest: fclean test

re: fclean all