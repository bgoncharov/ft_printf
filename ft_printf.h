/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 11:39:12 by bogoncha          #+#    #+#             */
/*   Updated: 2019/03/25 15:44:19 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_format
{
	char *conv;
	int flags;
	int precision;
}				t_format;

void ft_printf(const char *format, ...);
void flag_string(va_list valist);
void flag_int(va_list valist);
int converion_chars(char **format);
char *parse(const char *format, va_list valist);
int flag_chars(char **format);
int field_width(char **format);

#endif
