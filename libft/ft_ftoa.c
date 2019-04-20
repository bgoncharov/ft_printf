/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:24:25 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/20 13:08:49 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef union	u_double
{
	double		d;
	long		l;
}				t_double;

static void		ft_nbrcpy_p(long nb, int precision, char *str)
{
	if (precision > 1)
	{
		if (nb >= 10 || nb <= -10)
			ft_nbrcpy_p(nb / 10, precision - 1, str - 1);
		else
			ft_nbrcpy_p(0, precision - 1, str - 1);
	}
	if (nb < 0)
		*str = (ft_abs(nb % 10) + '0');
	else
		*str = (nb % 10 + '0');
}

static void		copy_fraction(char *str, double num, int precision, int offset)
{
	long	fraction;
	int		len_of_f;

	len_of_f = 0;
	while (len_of_f < precision && len_of_f < 17)
	{
		num *= 10;
		++len_of_f;
	}
	fraction = ft_round(num);
	ft_nbrcpy_p(fraction, len_of_f, str + offset + len_of_f); 
	if (precision > len_of_f)
		ft_nbrcpy_p(0, precision - len_of_f, str + offset + precision);
}

static char		*make_string(int sign, long intpart, double nb, int precision)
{
	int		len_of_i;
	char	*str;

	len_of_i = ft_numberlen(intpart);
	if (sign)
	{
		++len_of_i;
		str = ft_strnew(len_of_i + 1 + precision);
		*str = '-';
		ft_nbrcpy_p(intpart, len_of_i - 1, str + len_of_i - 1);
	}
	else
	{
		str = ft_strnew(len_of_i + 1 + precision);
		ft_nbrcpy_p(intpart, len_of_i, str + len_of_i - 1);
	}
	str[len_of_i] = '.';
	copy_fraction(str, nb, precision, len_of_i);
	return (str);
}

char			*ft_ftoa(double nb, int precision)
{
	t_double	unb;
	int			exp;
	long		mantissa;
	long		intpart;

	unb.d = nb;

	exp = ((unb.l >> 52) & 0x7ff) - 1023;
	mantissa = (unb.l & 0x000fffffffffffff);

	if (exp != 0x7FF && !(exp == 0 && mantissa == 0))
		mantissa |= (1L << 52);
	intpart = 0;
	if (exp > 0)
	{
		if (exp > 52)
			intpart = (mantissa << (exp - 52));
		else
			intpart = (mantissa >> (52 - exp));
	}
	return (make_string((unb.d < 0), intpart, unb.d, precision));
}
