/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rounding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:12:31 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/17 20:01:47 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ceil(double roundee)
{
	int	rounded;

	rounded = (int)roundee;
	if (rounded >= 0 && rounded < roundee)
		++rounded;
	else if (rounded < 0 && rounded > roundee)
		--rounded;
	return (rounded);
}

int		ft_floor(double roundee)
{
	int	rounded;

	rounded = (int)roundee;
	return (rounded);
}

long	ft_round(double roundee)
{
	long	rounded;

	if (roundee >= 0)
	{
		if ((roundee - (long)roundee) * 10 >= 5)
			rounded = (long)roundee + 1;
		else
			rounded = (long)roundee;
	}
	else
	{
		if ((roundee - (long)roundee) * -10 >= 5)
			rounded = (long)roundee - 1;
		else
			rounded = (long)roundee;
	}
	return (rounded);
}

long	ft_round_p(double roundee, int precision)
{
	long	rounded;
	int		difference;

	difference = ft_numberlen((long)roundee) - precision;
	while (difference-- > 0)
		roundee /= 10;
	if (roundee >= 0)
	{
		if ((roundee - (long)roundee) * 10 >= 5)
			rounded = (long)roundee + 1;
		else
			rounded = (long)roundee;
	}
	else
	{
		if ((roundee - (long)roundee) * -10 >= 5)
			rounded = (long)roundee - 1;
		else
			rounded = (long)roundee;
	}
	difference = ft_numberlen((long)roundee) - precision;
	while (difference-- > 0)
		rounded *= 10;
	return (rounded);
}
