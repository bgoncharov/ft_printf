# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/25 00:00:17 by bogoncha          #+#    #+#              #
#    Updated: 2019/03/25 00:00:19 by bogoncha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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