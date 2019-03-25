/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 11:39:02 by bogoncha          #+#    #+#             */
/*   Updated: 2019/03/24 16:23:57 by bogoncha         ###   ########.fr       */
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

int flag_launcher(char flag)
{
	char flags[10];
	int i;

	flags[0] = 's';
	flags[1] = 'd';
	i = 0;
	while (i < 2)
	{
		if (flags[i] == flag)
			return (i);
		++i;
	}
	return (-1);
}

char *parse(const char *format)
{
	char *loc;

	if (!(loc = ft_strchr(format, '%')))
		return (0);
	return (loc + 1);
}

void ft_printf(const char *format, ...)
{
	va_list valist;
	static void (*p[10])();
	char *ret;
	char *prev;

	va_start(valist, format);
	p[0] = flag_string;
	p[1] = flag_int;

	prev = (char*)format;
	ret = parse(prev);

	while (ret)
	{
		write (1, prev, (ret - prev) - 1);
		p[flag_launcher(*ret)](valist);
		prev = ret + 1;
		ret = parse(ret);
	}
	write(1, prev, ft_strlen(prev));
}
