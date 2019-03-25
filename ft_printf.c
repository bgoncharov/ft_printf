/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 11:39:02 by bogoncha          #+#    #+#             */
/*   Updated: 2019/03/24 23:46:15 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void flag_string(va_list valist)
{
	ft_putstr(va_arg(valist, char *));
}

void flag_int(va_list valist)
{
	ft_putnbr(va_arg(valist, int));
}

int converion_chars(char **format)
{
	const char *flags;

	flags = "sSpdDioOuUxXcC";
	if (ft_strchr(flags, **format))
		return (ft_strchr(flags, **format) - flags);
	return (-1);
}

int field_width(char **format)
{
	int width;

	width = 0;
	if (ft_isdigit(**format))
	{
		width = ft_atoi(*format);
		*format += ft_getnbsize(width);
	}
	return (width);
}

int flag_chars(char **format)
{
	const char *flags;
	int ret;

	flags = "#0-+ ";
	ret = -1;
	while (ft_strchr(flags, **format))
	{
		format++;
		ret = 1;
	}
	return (ret);
}

char *parse(const char *format, va_list valist)
{
	char *loc;
	int flags;
	int width;
	static void (*p[14])();

	p[0] = flag_string;
	p[3] = flag_int;
	p[5] = flag_int;

	if (!(loc = ft_strchr(format, '%')))
		return (0);
	loc++;
	flags = flag_chars(&loc);
	width = field_width(&loc);
	ft_putnbr(width);
	ft_putchar('\n');
	ft_putnbr(flags);
	ft_putchar('\n');
	p[converion_chars(&loc)](valist);
	ft_putchar('\n');
	return (loc + 1);
}

void ft_printf(const char *format, ...)
{
	va_list valist;
	char *p_str;

	va_start(valist, format);
	p_str = parse(format, valist);
	ft_putstr(p_str);
}
