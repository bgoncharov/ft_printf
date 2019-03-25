/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 11:39:02 by bogoncha          #+#    #+#             */
/*   Updated: 2019/03/25 16:12:09 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Task:
* 	conversions:	sSpdDioOuUxXcC
**	must manage:	%%
**	flags:			#0-+ (and ' ');
**	must manage:	minimum field-width and precision
**	flags:			hh, h, l, ll
**
** Bonuses :
**	conversions:	eE, fF, gG, aA, n
**	flags:			*, %, L, '
**	new flags:
**		%b:		binary
**		%r:		non-printable characters
**		%k:		date in ISO format
**	colors, fd, i td..
*/

void flag_string(va_list valist)
{
	ft_putstr(va_arg(valist, char *));
}

void flag_int(va_list valist)
{
	ft_putnbr(va_arg(valist, int));
}

char *flag_percent()
{
	return (ft_strdup("%"));
}

static char *parse(const char *format, va_list valist)
{
	t_format *fmt_struct;
	static void (*p[15])();

	p[0] = flag_string;
	p[3] = flag_int;
	p[5] = flag_int;
	p[14] = flag_percent;

	flag_chars(format);
	field_width(format);
	fmt_struct->conv = p[converion_chars(format)](valist);
	return (fmt_struct->conv);
}

void ft_printf(const char *format, ...)
{
	va_list valist;
	char *p_str;

	va_start(valist, format);
	while ((p_str = ft_strchr(format, '%')))
	{
		format += write(1, format, p_str - format) + 1;
		p_str = parse((char*)&format, valist);
		ft_putstr(p_str);
		ft_strdel(&p_str);
	}
	write (1, format, ft_strlen(format));
}
