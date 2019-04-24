/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flg_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 19:16:13 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/24 11:34:36 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void					append_flags(char *str, t_format *frmt)
{
	if (!(frmt->flags & MINUS))
		str += (frmt->width - frmt->precision);
	ft_strncpy(str, "0x", 2);
	str += 2;
	while (str && *str == ' ')
		*str++ = '0';
}

static void					ft_numcpy_hex(unsigned long long num, char *str)
{
	if (num >= 16)
		ft_numcpy_hex(num / 16, str - 1);
	if ((num % 16) >= 10)
		*str = ((num % 16) + 'a' - 10);
	else
		*str = ((num % 16) + '0');
}

char						*flg_pointer(t_format *frmt, va_list args)
{
	char				*str;
	unsigned long long	num;
	int					len;

	num = va_arg(args, unsigned long long);
	if (num == 0 && frmt->precision == 0)
		len = 0;
	else
		len = ft_unumberlen_base(num, 16);
	if (frmt->precision == -1 || frmt->precision < len)
		frmt->precision = len + 2;
	else
		frmt->precision += 2;
	frmt->width = ft_max(frmt->width, frmt->precision);
	str = ft_strinitial(frmt->width, ' ');
	if (frmt->flags & MINUS)
		ft_numcpy_hex(num, str + (frmt->precision - 1));
	else
		ft_numcpy_hex(num, str + (frmt->width - 1));
	append_flags(str, frmt);
	return (str);
}
