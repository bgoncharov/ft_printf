/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 10:52:15 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/22 11:13:41 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_bytes(wchar_t wc)
{
	int		i;

	i = 32;
	while (i > 0 && !(wc >> (i - 1)))
		--i;
	return ((i > 7) ? ((i + 3) / 5) : 1);
}

char		*conv_utf8_char(wchar_t wchar, char *str)
{
	char	*cur;
	int		bytes;

	bytes = get_bytes(wchar);
	if (!str && wchar)
		str = ft_strnew(bytes);
	if (!wchar || !str)
		return ((!wchar) ? ft_strnew(1) : 0);
	cur = str + bytes - 1;
	if (bytes > 1)
		while (cur >= str)
		{
			*cur |= (!(cur - str) ? (0xFF << (8 - bytes)) : 0x80);
			*cur |= (wchar & 0x3F);
			wchar = wchar >> 6;
			cur = (cur - str) ? (cur - 1) : 0;
		}
	else
		*cur = (char)wchar;
	return (str);
}

char		*conv_utf8_str(wchar_t *wstr)
{
	char	*str;
	int		bytes;
	int		totalbytes;

	totalbytes = 0;
	if (!wstr)
		return (0);
	while (wstr && *wstr)
		totalbytes += get_bytes(*wstr++);
	str = ft_strnew(totalbytes);
	str += totalbytes;
	while (totalbytes)
	{
		--wstr;
		bytes = get_bytes(*wstr);
		totalbytes -= bytes;
		str -= bytes;
		str = conv_utf8_char(*wstr, str);
	}
	return (str);
}