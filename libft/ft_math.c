/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 19:22:49 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/23 19:23:57 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int		ft_max(int a, int b)
{
	return ((a > b) ? a : b);
}

int		ft_min(int a, int b)
{
	return ((a < b) ? a : b);
}

long	ft_abs(long nb)
{
	return (nb < 0 ? (nb * -1) : nb);
}
