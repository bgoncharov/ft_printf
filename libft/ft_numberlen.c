/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numberlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:25:38 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/01 18:31:44 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_numlen_sign(long num)
{
	size_t	length;

	length = 1;
	if (num < 0)
	{
		num *= -1;
		++length;
	}
	while (num >= 10)
	{
		num /= 10;
		++length;
	}
	return (length);
}

size_t		ft_numberlen(long num)
{
	size_t	length;

	length = 1;
	while (num >= 10 || num <= -10)
	{
		num /= 10;
		++length;
	}
	return (length);
}
