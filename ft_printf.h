/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 11:39:12 by bogoncha          #+#    #+#             */
/*   Updated: 2019/03/31 12:13:36 by bogoncha         ###   ########.fr       */
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
	int conv;
	unsigned char flags;
	int width;
	int precision;
	char lenght;
}				t_format;

int ft_printf(const char *format, ...);

// function pointer functions
char *flag_string(t_format *fmt_struct, va_list valist);
char *flag_int(t_format *fmt_struct, va_list valist);
char *flag_percent(t_format *fmt_struct);

// parse functions
int conversion_chars(const char **format);
static char *parse(const char **format, va_list valist);
void get_width_precis(const char **format, t_format *fmt_struct);
void get_flags(const char **format, t_format *fmt_struct);
void get_size_flag(const char **format, t_format *fmt_struct);

static void add_precision(int precision, char **str);
static void print_params(t_format ftm_struct);
char *flag_char(t_format *fmt_struct, va_list valist);


#endif
