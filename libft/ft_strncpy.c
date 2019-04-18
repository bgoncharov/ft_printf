/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:04:44 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/17 18:40:40 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*cur;

	cur = dst;
	while (len && *src)
	{
		*cur++ = *src++;
		--len;
	}
	if (len)
		ft_nmemset(cur, '\0', len);
	return (dst);
}
