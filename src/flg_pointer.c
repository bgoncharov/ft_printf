/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flg_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 19:16:13 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/15 22:10:37 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*flg_pointer(t_format *frmt, va_list args)
{
	(void)args;
	(void)frmt;
	return(ft_strdup("flg_pointer"));
}
