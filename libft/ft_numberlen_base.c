/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numberlen_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:27:30 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/15 18:44:49 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numberlen_sign_base(long long num, int base)
{
	int length;

	length = 1;
	if (num < 0)
	{
		num *= -1;
		++length;
	}
	while (num >= base)
	{
		num /= base;
		++length;
	}
	return (length);
}

size_t	ft_numberlen_base(long long num, int base)
{
	int length;

	length = 1;
	while (num >= base || num <= -base)
	{
		num /= base;
		++length;
	}
	return (length);
}

size_t	ft_unumberlen_base(unsigned long long nb, int base)
{
	int length;

	length = 1;
	while (nb >= (unsigned int)base)
	{
		nb /= base;
		++length;
	}
	return (length);
}