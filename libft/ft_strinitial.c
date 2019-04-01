/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinitial.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:07:13 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/01 15:07:36 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strinitial(size_t size, int c)
{
	char	*str;

	str = (char *)ft_memset(malloc(size + 1), c, size + 1);
	if (str)
		str[size] = '\0';
	return (str);
}