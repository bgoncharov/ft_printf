# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/25 00:00:17 by bogoncha          #+#    #+#              #
#    Updated: 2019/03/26 18:05:17 by bogoncha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c parser.c main.c

OBJS = ft_printf.o parser.o main.o

all: $(NAME)

test: $(NAME) main.o
	@echo "\t\x1b[92;4mTest file compiled!\x1b[0m"

$(NAME): lib
	@gcc libft/libft.a $(SRC) -o test

lib:
	@make -C libft
	@echo "\t\x1b[92;4mLibft Done!\x1b[0m"

clean:
	@/bin/rm -rf $(OBJS)
	@make -C libft/ clean

fclean: clean
	@/bin/rm -rf test
	@make -C libft/ fclean

re: fclean all