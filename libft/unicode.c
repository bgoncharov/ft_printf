/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 10:52:15 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/22 10:53:12 by bogoncha         ###   ########.fr       */
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

char		*conv_utf8_char(wchar_t wc, char *s)
{
	char	*cur;
	int		bytes;

	bytes = get_bytes(wc);
	if (!s && wc)
		s = ft_strnew(bytes);
	if (!wc || !s)
		return ((!wc) ? ft_strnew(1) : 0);
	cur = s + bytes - 1;
	if (bytes > 1)
		while (cur >= s)
		{
			*cur |= (!(cur - s) ? (0xFF << (8 - bytes)) : 0x80);
			*cur |= (wc & 0x3F);
			wc = wc >> 6;
			cur = (cur - s) ? (cur - 1) : 0;
		}
	else
		*cur = (char)wc;
	return (s);
}

char		*conv_utf8_str(wchar_t *ws, char *s)
{
	int		bytes;
	int		totalbytes;

	totalbytes = 0;
	if (!ws)
		return (0);
	while (ws && *ws)
		totalbytes += get_bytes(*ws++);
	s = ft_strnew(totalbytes);
	s += totalbytes;
	while (totalbytes)
	{
		--ws;
		bytes = get_bytes(*ws);
		totalbytes -= bytes;
		s -= bytes;
		s = conv_utf8_char(*ws, s);
	}
	return (s);
}