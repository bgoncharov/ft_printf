/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flg_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:31:04 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/24 11:23:22 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*addspaces(char **str, int spaces, int left)
{
	int		len_str;
	char	*newstr;

	len_str = ft_strlen(*str);
	newstr = ft_strinitial(len_str + spaces, ' ');
	if (left)
		ft_strncpy(newstr, *str, len_str);
	else
		ft_strncpy(newstr + spaces, *str, len_str);
	ft_strdel(str);
	return (newstr);
}

static double	get_num(char length, va_list args)
{
	double	num;

	num = 0;
	if (length == 0)
		num = va_arg(args, double);
	else if (length == 'l')
		num = va_arg(args, double);
	else if (length == 'L')
		num = va_arg(args, long double);
	return (num);
}

char			*flg_float(t_format *frmt, va_list args)
{
	double	num;
	char	*str;
	int		len;

	num = get_num(frmt->lenght, args);
	if (frmt->precision == -1)
		frmt->precision = 6;
	str = ft_ftoa(num, frmt->precision);
	len = ft_strlen(str);
	if (frmt->width > len)
		str = addspaces(&str, frmt->width - len, frmt->flags & MINUS);
	frmt->width = ft_strlen(str);
	return (str);
}
