# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/25 00:00:17 by bogoncha          #+#    #+#              #
#    Updated: 2019/03/28 23:01:20 by bogoncha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c parser.c char_string.c main.c

OBJS = ft_printf.o parser.o char_string.o main.o

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