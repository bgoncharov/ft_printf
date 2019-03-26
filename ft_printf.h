/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 11:39:12 by bogoncha          #+#    #+#             */
/*   Updated: 2019/03/25 21:11:15 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_format
{
	char *conv;
	int flags;
	int width;
	int precision;
}				t_format;

void ft_printf(const char *format, ...);

// function pointer functions
char *flag_string(va_list valist);
char *flag_int(va_list valist);
char *flag_percent();

// parse functions
int conversion_chars(char **format);
static char *parse(char **format, va_list valist);
void width_precision(char **format, t_format *fmt_struct);
void flag_chars(char **format, t_format *fmt_struct);

#endif
