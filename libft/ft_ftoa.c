/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:24:25 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/20 18:24:52 by bogoncha         ###   ########.fr       */
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

/*
** Gather fraction part without bits
*/

static void		copy_fraction(char *str, double num, int precision, int offset)
{
	long	fraction;
	int		len_f;
	int		leading_zeros;

	len_f = 0;
	leading_zeros = 0;
	while (leading_zeros + len_f < precision && (len_f + offset < 17))
	{
		num *= 10;
		if (num < -1 || num > 1)
			++len_f;
		else
			++leading_zeros;
	}
	fraction = ft_round(num);
	if (fraction > 0 && len_f == 0)
		++len_f;
	if (leading_zeros)
		ft_nbrcpy_p(0, leading_zeros, str + offset + leading_zeros);
	if (len_f)
		ft_nbrcpy_p(fraction, len_f, str + offset + leading_zeros + len_f);
	if (precision > len_f + leading_zeros)
		ft_nbrcpy_p(0, precision - len_f, str + offset + precision);
}

static long		get_intpart(double num, int *trailing_zeros)
{
	long	intpart;

	*trailing_zeros = 0;
	while (num >= (1UL << 63))
	{
		num /= 10;
		++(*trailing_zeros);
	}
	if (*trailing_zeros)
		intpart = ft_round(num);
	else
		intpart = (long)num;
	return (intpart);
}

static char		*make_string(int sign, double num, int precision)
{
	long	intpart;
	int		len_i;
	int		trailing_zeros;
	char	*str;

	intpart = get_intpart(num, &trailing_zeros);
	len_i = ft_numberlen(intpart);
	if (sign)
	{
		++len_i;
		str = ft_strnew(len_i + trailing_zeros + 1 + precision);
		*str = '-';
		ft_nbrcpy_p(intpart, len_i - 1, str + len_i - 1);
	}
	else
	{
		str = ft_strnew(len_i + trailing_zeros + 1 + precision);
		ft_nbrcpy_p(intpart, len_i, str + len_i - 1);
	}
	if (trailing_zeros)
		ft_nbrcpy_p(0, trailing_zeros, str + len_i + trailing_zeros - 1);
	if (precision)
		str[len_i + trailing_zeros] = '.';
	copy_fraction(str, num, precision, len_i + trailing_zeros);
	return (str);
}

char			*ft_ftoa(double nb, int precision)
{
	t_double	unb;
	int			exp;
	long		mantissa;

	unb.d = nb;
	exp = ((unb.l >> 52) & 0x7ff);
	mantissa = (unb.l & 0x000fffffffffffff);
	if (exp == 0x7ff)
	{
		if (mantissa)
			return (ft_strdup("nan"));
		else
			if (unb.l & (1L << 63))
				return (ft_strdup("-inf"));
			else
				return (ft_strdup("inf"));
	}
	return (make_string(((unb.l >> 63) & 1), nb, precision));
}
