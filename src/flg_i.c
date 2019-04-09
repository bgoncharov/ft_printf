/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:46:45 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/04 15:12:56 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static long long take_num(char length, va_list args)
{
	long long num;

	num = 0;
	if (length == 0)
		num = va_arg(args, int);
	else if (length == 'l')
		num = va_arg(args, long);
	else if (length == 'L')
		num = va_arg(args, long long);
	else if (length == 'h')
		num = va_arg(args, int);
	else if (length == 'H')
		num = va_arg(args, int);
	else if (length == 'j')
		num = va_arg(args, long long);
	else if (length == 'z')
		num = va_arg(args, size_t);
	return (num);
}

static void	append_flags(char *str, t_format *frmt, long long num)
{
	if (!(frmt->flags & MINUS))
		str += (frmt->width - frmt->precision);
	if (((frmt->flags & (PLUS | SPACE)) || num < 0))
	{
		if (num < 0)
			*str++ = '-';
		else if ((frmt->flags & PLUS) && num >= 0)
			*str++ = '+';
		else if ((frmt->flags & SPACE) && num >= 0)
			*str++ = ' ';
	}
	while (str && *str == ' ')
		*str++ = '0';
}

static void	ft_numcpy(long long num, char *str)
{
	if (num >= 10 || num <= -10)
		ft_numcpy(num / 10, str - 1);
	if (num < 0)
		*str = (ft_abs(num % 10) + '0');
	else
		*str = (num % 10 + '0');
}

static char	*num_format(t_format *frmt, long long num, int len)
{
	if (frmt->precision != -1)
	{
		if (frmt->precision < len)
			frmt->precision = len;
		if ((frmt->flags & (PLUS | SPACE)) || num < 0)
			++frmt->precision;
		if (frmt->precision > frmt->width)
			frmt->width = frmt->precision;
	}
	else
	{
		frmt->width = ft_max(frmt->width, len);
        frmt->precision = len;
		if (((frmt->flags & (PLUS | SPACE)) || num < 0))
        {
            ++frmt->precision;
            if (frmt->width == len)
			    ++frmt->width;
        }
		if (frmt->flags & ZERO)
			frmt->precision = frmt->width;
	}
	return (ft_strinitial(frmt->width, ' '));
}

char		*flg_int(t_format *frmt_struct, va_list args)
{
	char		*new;
	long long	num;
    int			len;

	num = take_num(frmt_struct->lenght, args);
    if (frmt_struct->precision == 0 && num == 0)
        len = 0;
    else
        len = ft_numberlen(num);    
	new = num_format(frmt_struct, num, len);
    if (len)
    {
        if (frmt_struct->flags & MINUS)
            ft_numcpy(num, new + (frmt_struct->precision - 1));
        else
            ft_numcpy(num, new + (frmt_struct->width - 1));
    }
	append_flags(new, frmt_struct, num);
	return (new);
}
