/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flg_unicode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 11:02:10 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/22 11:06:33 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char			*flg_wstr(t_format *frmt, va_list args)
{
	wchar_t	*str;
	char	*newstr;

	str = va_arg(args, wchar_t *);
	if (!str)
		str = "(null)";
	newstr = conv_utf8_str(str);
	return (newstr);
}

char			*flg_wchar(t_format *frmt, va_list args)
{
	wchar_t	c;
	char	*newstr;

	c = va_arg(args, wchar_t);
	newstr = conv_utf8_char(c, 0);
	return (newstr);
}