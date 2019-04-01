/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:07:57 by bogoncha          #+#    #+#             */
/*   Updated: 2019/03/31 20:30:31 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** correttly cut the string
*/
static void add_precision(int precision, char **str)
{
	int len;
	char *new;

	len = ft_strlen(*str);
	if ((precision != -1) && len > precision)
	{
		new = ft_strndup(*str, precision);
		ft_strdel(str);
		*str = new;
	}
}

static void	add_width(int width, char **str, int is_left)
{
	int len;
	char *newstr;

	len = ft_strlen(*str);
	if (width > len)
	{
		newstr = ft_memset(ft_strnew(width), ' ', width);
		if (is_left)
			ft_strncpy(newstr, *str, len);
		else
			ft_strncpy(newstr + (width - len), *str, len);
		ft_strdel(str);
		*str = newstr;
	}
}

char *flag_char(t_format *fmt_struct, va_list valist)
{
	char c;
	char *str;

	//print_params(*fmt_struct);
	c = (char)va_arg(valist, int);
	if (!c)
		str = ft_strdup("^@");
	str = ft_strndup(&c, 1);
	add_width(fmt_struct->width, &str, (fmt_struct->flags & MINUS));
	return (ft_strdup(&c));
}

char *flag_string(t_format *fmt_struct, va_list valist)
{
	char *str;

	//print_params(*fmt_struct);
	str = va_arg(valist, char *);
	if (!str)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	add_precision(fmt_struct->precision, &str);
	add_width(fmt_struct->width, &str, (fmt_struct->flags & MINUS));
	return (str);
}

char *flag_percent(t_format *fmt_struct)
{
	char *str;
	//print_params(*fmt_struct);
	str = ft_strdup("%");
	add_width(fmt_struct->width, &str, (fmt_struct->flags & MINUS));
	return (str);
}
