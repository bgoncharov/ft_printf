/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:23:10 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/15 20:09:21 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	if (*alst)
		del((*alst)->content, (*alst)->content_size);
	ft_memdel((void **)alst);
}

void	ft_lstmemdel(void *content, size_t content_size)
{
	ft_memdel(&content);
	(void)content_size;
}
