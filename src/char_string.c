/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:07:57 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/01 16:27:52 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** correttly cut the string
*/
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

char *flg_char(t_format *frmt_struct, va_list args)
{
	char c;
	char *new;

	//print_params(*fmt_struct);
	c = (char)va_arg(args, int);
	if (!c)
		new = ft_strdup("^@");
	new = ft_strndup(&c, 1);
	add_width(frmt_struct->width, &new, (frmt_struct->flags & MINUS));
	return (ft_strdup(&c));
}

char *flg_str(t_format *frmt_struct, va_list args)
{
	char *str;

	//print_params(*fmt_struct);
	str = va_arg(args, char *);
	if (!str)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	add_prec(frmt_struct->precision, &str);
	add_width(frmt_struct->width, &str, (frmt_struct->flags & MINUS));
	return (str);
}

char *flg_percent(t_format *frmt_struct)
{
	char *str;
	//print_params(*fmt_struct);
	str = ft_strdup("%");
	add_width(frmt_struct->width, &str, (frmt_struct->flags & MINUS));
	return (str);
}
