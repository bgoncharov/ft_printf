# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/25 00:00:17 by bogoncha          #+#    #+#              #
#    Updated: 2019/04/24 15:46:31 by bogoncha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=			libftprintf.a

INCLUDE_DIR :=	./includes
L_OBJS :=		$(patsubst %.c,%.o,$(wildcard ./srcs/*.c))
C_OBJS :=		$(patsubst %.c,%.o,$(wildcard ./srcs/ft_printf/*.c))

CFLAGS +=		-Wall -Wextra -Werror -I$(INCLUDE_DIR)
LDFLAGS +=		-L./ -lftprintf

.PHONY:			all clean fclean re

all: $(NAME)

$(NAME): $(L_OBJS) $(C_OBJS)
	ar rc $(NAME) $(L_OBJS) $(C_OBJS)
	ranlib $(NAME)

test: all main.o
	$(CC) $(CFLAGS) main.o -o test $(LDFLAGS)

clean:
	@- $(RM) $(C_OBJS) $(L_OBJS) main.o

fclean: clean
	@- $(RM) $(NAME) test

re: fclean all
