/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flg_oct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:17:56 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/24 20:33:07 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long	take_num(char conv, char length, va_list args)
{
	unsigned long long		num;

	num = 0;
	if (conv == 'O')
	{
		if (length == 'l' || length == 'L')
			length = 'L';
		else
			length = 'l';
	}
	if (length == 0)
		num = va_arg(args, unsigned int);
	else if (length == 'l')
		num = va_arg(args, unsigned long);
	else if (length == 'L')
		num = va_arg(args, unsigned long long);
	else if (length == 'h')
		num = (unsigned short)va_arg(args, unsigned int);
	else if (length == 'H')
		num = (unsigned short)va_arg(args, unsigned int);
	else if (length == 'j')
		num = va_arg(args, unsigned long long);
	else if (length == 'z')
		num = va_arg(args, size_t);
	return (num);
}

static void					append_flags(char *str, t_format *frmt, int len)
{
	if (!(frmt->flags & MINUS))
		str += (frmt->width - frmt->precision);
	if (frmt->flags & SHARP && len == 0)
		++len;
	if (len)
	{
		while (str && *str == ' ')
			*str++ = '0';
	}
}

static void					ft_numcpy_oct(unsigned long long num, char *str)
{
	if (num >= 8)
		ft_numcpy_oct(num / 8, str - 1);
	*str = ((num % 8) + '0');
}

static char					*num_format(t_format *frmt,
		unsigned long long num, int len)
{
	if (frmt->precision != -1)
	{
		if (frmt->flags & SHARP && frmt->precision <= len)
			++len;
		if (frmt->precision < len)
			frmt->precision = len;
		if (frmt->precision > frmt->width)
			frmt->width = frmt->precision;
	}
	else
	{
		if (frmt->flags & SHARP && num != 0)
			++len;
		frmt->width = ft_max(frmt->width, len);
		frmt->precision = len;
		if (frmt->flags & ZERO)
			frmt->precision = frmt->width;
	}
	return (ft_strinitial(frmt->width, ' '));
}

char						*flg_oct(t_format *frmt, va_list args)
{
	char					*new;
	long long				num;
	int						len;

	num = take_num(frmt->conv, frmt->lenght, args);
	if (frmt->precision == 0 && num == 0)
	{
		len = 0;
		if (frmt->flags & SHARP)
			++frmt->precision;
	}
	else
		len = ft_numberlen_base(num, 8);
	new = num_format(frmt, num, len);
	if (len)
	{
		if (frmt->flags & MINUS)
			ft_numcpy_oct(num, new + (frmt->precision - 1));
		else
			ft_numcpy_oct(num, new + (frmt->width - 1));
	}
	append_flags(new, frmt, len);
	return (new);
}
