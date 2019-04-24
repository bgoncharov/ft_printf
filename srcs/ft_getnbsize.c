/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 14:42:28 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/01 12:07:17 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getnbsize(long n)
{
	long len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < len)
		len += 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
