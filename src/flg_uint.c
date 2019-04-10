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

static unsigned long long take_num(char length, va_list args)
{
	unsigned long long num;

	num = 0;
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

static void	append_flags(char *str, t_format *frmt, int len)
{
	if (!(fmt->flags & MINUS))
		str += (fmt->width - fmt->precision);
	if (len)
	{
		while (str && *str == ' ')
			*str++ = '0';
	}
}

static void	ft_numcpy(unsigned long long num, char *str)
{
	if (nb >= 10)
		ft_nbrcpy(nb / 10, str - 1);
	*str = (nb % 10 + '0');
}

static char	*num_format(t_format *frmt, long long num, int len)
{
	if (frmt->precision != -1)
	{
		if (frmt->precision < len)
			frmt->precision = len;
		if (frmt->precision > frmt->width)
			frmt->width = frmt->precision;
	}
	else
	{
		fmt->width = ft_max(fmt->width, len);
		fmt->precision = len;
		if (fmt->flags & ZERO)
			fmt->precision = fmt->width;
	}
	return (ft_strinit(fmt->width, ' '));
}

char		*flg_uint(t_format *frmt, va_list args)
{
	char		*new;
	long long	num;
    int			len;

	num = take_num(frmt->lenght, args);
    if (frmt->precision == 0 && num == 0)
        len = 0;
    else
        len = ft_numberlen(num);    
	new = num_format(frmt, num, len);
    if (len)
    {
        if (frmt->flags & MINUS)
            ft_numcpy(num, new + (frmt->precision - 1));
        else
            ft_numcpy(num, new + (frmt->width - 1));
    }
	append_flags(new, frmt, num, len);
	return (new);
}
