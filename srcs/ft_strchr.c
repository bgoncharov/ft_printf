/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:26:07 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/22 10:37:07 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int symbol)
{
	while (*string)
	{
		if (*string == (char)symbol)
			return ((char *)(string));
		++string;
	}
	return ((char)symbol == '\0' ? (char *)string : 0);
}
