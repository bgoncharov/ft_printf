/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:07:57 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/07 12:59:00 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** correttly cut the string
static void add_prec(int prec, char **str)
{
	int len;
	char *new;

	len = ft_strlen(*str);
	if ((prec != -1) && len > prec)
	{
		new = ft_strndup(*str, prec);
		ft_strdel(str);
		*str = new;
	}
}
*/

static void	add_width(int width, char **str, int left)
{
	int len;
	char *new;

	len = ft_strlen(*str);
	if (width > len)
	{
		new = ft_memset(ft_strnew(width), ' ', width);
		if (left)
			ft_strncpy(new, *str, len);
		else
			ft_strncpy(new + (width - len), *str, len);
		ft_strdel(str);
		*str = new;
	}
}

static char *frmt_str(t_format *frmt, int len)
{
	if (frmt->precision != -1)
	{
		if (frmt->precision > len)
			frmt->precision = len;
		if (frmt->precision > frmt->width)
			frmt->width = frmt->precision;
	}
	else
	{
		frmt->width = ft_max(frmt->width, len);
		frmt->precision = len;
	}
	return (ft_strinitial(frmt->width, ' '));
}

char *flg_char(t_format *frmt, va_list args)
{
	char c;
	char *new;

	//print_params(*fmt_struct);
	c = (char)va_arg(args, int);
	if (!c)
		new = ft_strdup("^@");
	new = ft_strndup(&c, 1);
	add_width(frmt->width, &new, (frmt->flags & MINUS));
	return (new);
}

char *flg_str(t_format *frmt, va_list args)
{
	char *str;
	char *new;
	int len;

	//print_params(*fmt_struct);
	str = va_arg(args, char *);
	if (!str)
	{
		str = "(null)";
		len = 6;
	}
	else
		len = ft_strlen(str);
	new = frmt_str(frmt, len);
	if (frmt->flags & MINUS)
		ft_strncpy(new, str, frmt->precision);
	else
		ft_strncpy(new + frmt->width - frmt->precision, str, frmt->precision);	
	return (new);
}

char *flg_percent(t_format *frmt)
{
	char *str;
	//print_params(*fmt_struct);
	str = ft_strdup("%");
	add_width(frmt->width, &str, (frmt->flags & MINUS));
	return (str);
}
