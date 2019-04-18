/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmemset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:39:57 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/17 18:40:10 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_nmemset(void *b, int c, size_t len)
{
	unsigned char	*cur;

	cur = b;
	while (len-- && cur)
		*cur++ = (unsigned char)c;
	return (b);
}
