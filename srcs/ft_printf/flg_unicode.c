/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flg_unicode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 11:02:10 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/24 11:48:34 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*addspaces(char **str, int spaces, int left)
{
	int		len_str;
	char	*newstr;

	len_str = ft_strlen(*str);
	newstr = ft_strinitial(len_str + spaces, ' ');
	if (left)
		ft_strncpy(newstr, *str, len_str);
	else
		ft_strncpy(newstr + spaces, *str, len_str);
	ft_strdel(str);
	return (newstr);
}

static int		get_bytes(wchar_t wc)
{
	int		i;

	i = 32;
	while (i > 0 && !(wc >> (i - 1)))
		--i;
	return ((i > 7) ? ((i + 3) / 5) : 1);
}

static char		*conv_utf8_str_precision(wchar_t *wstr, int precision)
{
	char	*str;
	int		bytes;
	int		totalbytes;
	int		i;

	if (!wstr)
		return (0);
	totalbytes = 0;
	i = 0;
	while (wstr && *wstr && i < precision)
	{
		totalbytes += get_bytes(*wstr++);
		++i;
	}
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

char			*flg_wstr(t_format *frmt, va_list args)
{
	wchar_t	*str;
	char	*newstr;
	int		len;

	str = va_arg(args, wchar_t *);
	if (!str)
		str = L"(null)";
	len = ft_wstrlen(str);
	if (frmt->precision > len || frmt->precision == -1)
		frmt->precision = len;
	if (frmt->width < frmt->precision)
		frmt->width = frmt->precision;
	newstr = conv_utf8_str_precision(str, frmt->precision);
	if (frmt->width > frmt->precision)
		newstr = addspaces(&newstr, frmt->width - frmt->precision,
				frmt->flags & MINUS);
	frmt->width = ft_strlen(newstr);
	return (newstr);
}

char			*flg_wchar(t_format *frmt, va_list args)
{
	wchar_t	c;
	char	*newstr;

	c = va_arg(args, wchar_t);
	newstr = conv_utf8_char(c, 0);
	if (frmt->width > 1)
		newstr = addspaces(&newstr, frmt->width - 1, frmt->flags & MINUS);
	frmt->width = ft_strlen(newstr);
	return (newstr);
}
