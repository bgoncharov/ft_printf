/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 21:04:50 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/23 19:03:46 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*s2;
	size_t	i;

	i = 0;
	while (s[i])
		i += 1;
	if (!(s2 = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		s2[i] = s[i];
		i += 1;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strndup(const char *s1, size_t len)
{
	char	*dup;

	dup = ft_strnew(len);
	return (dup ? ft_strncpy(dup, s1, len) : 0);
}
