/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:18:00 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/23 19:01:08 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstadd(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}

void	ft_lstadd_tail(t_list **alst, t_list *item)
{
	t_list **cur;

	cur = alst;
	if (!*cur)
	{
		*cur = item;
		return ;
	}
	while ((*cur)->next)
		cur = &(*cur)->next;
	(*cur)->next = item;
}
