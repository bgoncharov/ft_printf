/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 11:39:02 by bogoncha          #+#    #+#             */
/*   Updated: 2019/03/25 22:18:39 by bogoncha         ###   ########.fr       */
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

t_format *new_fmt_struct()
{
	t_format *fmt;

	fmt = (t_format *)ft_memalloc(sizeof(t_format));
	fmt->conv = 0;
	fmt->flags = 0;
	fmt->width = 0;
	fmt->precision = 0;
	return (fmt);
}

char *flag_string(va_list valist)
{
	return (va_arg(valist, char *));
}

char *flag_int(va_list valist)
{
	return (ft_itoa(va_arg(valist, int)));
}

char *flag_percent()
{
	return (ft_strdup("%"));
}

static char *parse(char **format, va_list valist)
{
	t_format *fmt_struct;
	static char *(*p[15])();

	fmt_struct = new_fmt_struct();
	p[0] = flag_string;
	p[3] = flag_int;
	p[5] = flag_int;
	p[14] = flag_percent;

	flag_chars(format, fmt_struct);
	width_precision(format, fmt_struct);
	printf("flags: %s\n", ft_itoa_base(fmt_struct->flags, 2));
	printf("width: %d\n", fmt_struct->width);
	printf("precision: %d\n\n", fmt_struct->precision);
	fmt_struct->conv = p[conversion_chars(format)](valist);
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
		p_str = parse((char**)&format, valist);
		ft_putstr(p_str);
		ft_strdel(&p_str);
	}
	write (1, format, ft_strlen(format));
}
