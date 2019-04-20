/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:24:25 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/20 12:23:32 by bogoncha         ###   ########.fr       */
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

static long		get_fraction(int exp, long mantissa, int precision)
{
	int			index;
	int			max;
	t_double	multiple;
	double		fraction;

	index = 1;
	if (exp < 0)
		index += -(exp) - (mantissa ? 1 : 0);
	multiple.d = (double)ft_power(10, precision);
	max = ((precision + 1) * 3) + ft_ceil((double)((precision + 1) / 3));
	fraction = 0;
	while (index <= max)
	{
		if (mantissa & (1L << ((52 - exp) - index)))
			fraction += multiple.d / (1L << index);
		++index;
	}

	return(ft_round(fraction));
}

static char		*make_string(int sign, int exp, long mantissa, int precision)
{
	long	intpart;
	int		len_of_intpart;
	long	fraction;
	char	*str;

	intpart = 0;
	if (exp > 0)
		intpart = (mantissa >> (52 - exp));
	len_of_intpart = ft_numberlen(intpart);
	fraction = get_fraction(exp, mantissa, precision);
	if (sign)
	{
		++len_of_intpart;
		str = ft_strnew(len_of_intpart + 1 + precision);
		*str = '-';
		ft_nbrcpy_p(intpart, len_of_intpart - 1, str + len_of_intpart - 1);
	}
	else
	{
		str = ft_strnew(len_of_intpart + 1 + precision);
		ft_nbrcpy_p(intpart, len_of_intpart, str + len_of_intpart - 1);
	}
	str[len_of_intpart] = '.';
	ft_nbrcpy_p(fraction, precision, str + len_of_intpart + precision); 
	return (str);
}

char			*ft_ftoa(double nb, int precision)
{
	t_double	unb;
	int			sign;
	int			exp;
	long		mantissa;
	char		*str;

	unb.d = nb;
	sign = !!(unb.l & 0x8000000000000000);
	exp = ((unb.l >> 52) & 0x7ff) - 1023;
	mantissa = (unb.l & 0x000fffffffffffff);
	if (exp != 0x7FF && !(exp == 0 && mantissa == 0))
		mantissa |= (1L << 52);
	str = make_string(sign, exp, mantissa, precision);

	return (str);
}
