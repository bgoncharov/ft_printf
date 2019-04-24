/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstputstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 22:58:14 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/23 19:01:30 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void				ft_lstputstr(t_list *item)
{
	if (item)
		write(1, (char *)item->content, ft_strlen(item->content));
}

void				ft_lstputstr_len(t_list *item)
{
	if (item)
		write(1, (char *)item->content, item->content_size);
}
