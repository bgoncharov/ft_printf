/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rounding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:12:31 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/17 19:12:33 by bogoncha         ###   ########.fr       */
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
