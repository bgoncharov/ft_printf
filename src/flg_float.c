/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flg_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:31:04 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/17 20:03:07 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

typedef union	u_double
{
	double		d;
	long		l;
}				t_double;

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

char			*flg_float(t_format *frmt, va_list valist)
{
	double	num;
	char	*str;

	num = get_num(frmt->lenght, valist);
	str = ft_ftoa(num, frmt->precision);

	frmt->width = ft_strlen(str);
	return (str);
}