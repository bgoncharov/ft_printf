/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flg_scpercent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:07:57 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/24 21:07:47 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*frmt_str(t_format *frmt, char *str, int len)
{
	if (frmt->precision != -1)
	{
		if (frmt->precision > len)
			frmt->precision = len;
		else if (frmt->precision < len && !str)
			frmt->precision = 0;
		if (frmt->precision > frmt->width)
			frmt->width = frmt->precision;
	}
	else
	{
		frmt->width = ft_max(frmt->width, len);
		frmt->precision = len;
	}
	return (ft_strinitial(frmt->width, ' '));
}

char		*flg_char(t_format *frmt, va_list args)
{
	char	c;
	char	*new;

	c = (char)va_arg(args, int);
	if (frmt->width < 1)
		frmt->width = 1;
	new = ft_strinitial(frmt->width, ' ');
	if (frmt->flags & MINUS)
		new[0] = c;
	else
		new[frmt->width - 1] = c;
	return (new);
}

char		*flg_str(t_format *frmt, va_list args)
{
	char	*str;
	char	*new;
	int		len;

	if (frmt->lenght == 'l')
		return (flg_wstr(frmt, args));
	str = va_arg(args, char *);
	if (!str)
		len = 6;
	else
		len = ft_strlen(str);
	new = frmt_str(frmt, str, len);
	if (!str)
		str = "(null)";
	if (frmt->flags & MINUS)
		ft_strncpy(new, str, frmt->precision);
	else
		ft_strncpy(new + frmt->width - frmt->precision, str, frmt->precision);
	return (new);
}

char		*flg_percent(t_format *frmt)
{
	char	*str;

	if (frmt->width < 1)
		frmt->width = 1;
	str = ft_strinitial(frmt->width, ' ');
	if (frmt->flags & MINUS)
		str[0] = '%';
	else
		str[frmt->width - 1] = '%';
	return (str);
}
