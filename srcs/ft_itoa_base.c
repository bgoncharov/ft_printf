/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 19:21:00 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/24 10:42:23 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	append_character(char *dest, char src)
{
	while (*dest)
		dest++;
	*dest++ = src;
	*dest = '\0';
}

static void	recursive_strfill_base(char *str, long num, int base)
{
	if (num >= base)
		recursive_strfill_base(str, num / base, base);
	if (base > 10 && (num % base) > 9)
		append_character(str, ('A' + (num % base) - 10));
	else
		append_character(str, ('0' + num % base));
}

char		*ft_itoa_base(int n, int base)
{
	char *str;
	long num;

	num = (long)(n < 0 ? (n * -1) : n);
	if (n < 0 && base == 10)
	{
		str = ft_strnew(ft_numberlen_base(num, base) + 1);
		if (!str)
			return (0);
		*str = '-';
	}
	else
	{
		str = ft_strnew(ft_numberlen_base(num, base));
		if (!str)
			return (0);
	}
	recursive_strfill_base(str, num, base);
	return (str);
}
