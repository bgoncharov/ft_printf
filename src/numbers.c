/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:46:45 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/01 16:30:16 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*num_format(t_format *frmt, int num)
{
	int		len;
	char	*str;

	len = ft_getnbsize(num);
	len = ((num < 0) ? (len - 1) : len);
	if (frmt->precision == 0 && num == 0)
		len = 0;
	if (frmt->precision != -1)
	{
		if ((frmt->flags & (PLUS | SPACE)) || num < 0)
			++frmt->precision;
		if (frmt->precision > frmt->width)
			frmt->width = frmt->precision;
	}
	else
	{
		frmt->width = ft_max(frmt->width, len);
		if (((frmt->flags & (PLUS | SPACE)) || num < 0) && frmt->width == len)
			++frmt->width;
		if (frmt->flags & ZERO)
			frmt->precision = frmt->width;
	}
	str = ft_strinitial(frmt->width, ' ');
	ft_putstr("w: ");
	ft_putnbr(frmt->width);
	ft_putstr(", p: ");
	ft_putnbr(frmt->precision);
	ft_putstr(", l: ");
	ft_putnbr(len);
	ft_putstr("	");
	return (str);
}

char		*flg_int(t_format *frmt_struct, va_list args)
{
	char	*new;
	int		num;

	num = va_arg(args, int);
	new = num_format(frmt_struct, num);
	return (new);
}
