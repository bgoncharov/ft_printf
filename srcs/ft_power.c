/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:18:17 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/20 16:39:46 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_power(int a, int b)
{
	long	power;

	power = 1;
	while (b > 0)
	{
		power *= a;
		--b;
	}
	return (power);
}

double	ft_power_d(double a, int b)
{
	double	power;

	power = 1;
	while (b > 0)
	{
		power *= a;
		--b;
	}
	return (power);
}
