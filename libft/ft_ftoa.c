/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:24:25 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/20 18:12:26 by bogoncha         ###   ########.fr       */
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
		*str = ((nb % 10) + '0');
}

static void		copy_fraction(char *str, double num, int precision, int offset)
{
	double	fraction;
	int		len_of_f;
	int		leading_zeros;

	len_of_f = 0;
	leading_zeros = 0;
	while (leading_zeros + len_of_f < precision && (len_of_f + offset < 17))
	{
		num *= 10;
		if (num < -1 || num > 1)
			++len_of_f;
		else
			++leading_zeros;
	}
	fraction = ft_round(num);

	if (leading_zeros)
		ft_nbrcpy_p(0, leading_zeros, str + offset + leading_zeros);
	ft_nbrcpy_p(fraction, len_of_f, str + offset + leading_zeros + len_of_f);
	if (precision > len_of_f + leading_zeros)
		ft_nbrcpy_p(0, precision - len_of_f, str + offset + precision);
}

static char		*make_string(int sign, long intpart, double num, int precision)
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
	copy_fraction(str, num, precision, len_of_i);
	return (str);
}

static long		get_intpart(int exp, long mantissa)
{
	long	intpart;

	intpart = 0;
	if (52 <= exp && exp < 64)
		intpart = (mantissa << (exp - 52));
	else if (0 <= exp && exp < 52)
		intpart = (mantissa >> (52 - exp));
	return (intpart);
}

char			*ft_ftoa(double nb, int precision)
{
	t_double	unb;
	int			exp;
	long		mantissa;
	long		intpart;

	unb.d = nb;
	exp = ((unb.l >> 52) & 0x7ff);
	mantissa = (unb.l & 0x000fffffffffffff);
	if (exp == 0x7ff)
		if (mantissa)
			return (ft_strdup("nan"));
		else
			if (unb.l & (1L << 63))
				return (ft_strdup("-inf"));
			else
				return (ft_strdup("inf"));
	else if (exp != 0)
		mantissa |= (1L << 52);
	exp -= 0x3ff;
	intpart = get_intpart(exp, mantissa);
	return (make_string(((unb.l >> 63) & 1), intpart, nb, precision));
}
