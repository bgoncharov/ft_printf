/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:02:59 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/23 19:23:30 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_dstrlen(const char *str, char del)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != del)
		i++;
	return (i);
}
