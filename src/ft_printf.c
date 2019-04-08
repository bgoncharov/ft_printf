/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 11:39:02 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/07 20:25:23 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** Task:
* 	conversions:	sSpdDioOuUxXcC
**	must manage:	%%
**	flags:			#0-+ (and ' ');
**	must manage:	minimum field-width and precision
**	flags:			hh, h, l, ll
**
**	.___________________________________.
**	|conversion	|	length		|flags	|
**	|-----------+---------------+-------|
**	|	c		|				|		|
**	|	s		|				|		|
**	|	p		|				|		|
**	|-----------+---------------+-------|
**	|	d		| h, hh, l, ll	| 0-+s	|
**	|	i		| h, hh, l, ll	| 0-+s	|
**	|	o		| h, hh, l, ll	| 0-+s	|
**	|	u		| h, hh, l, ll	| 0-+s	|
**	|	x		| h, hh, l, ll	| 0-+s	|
**	|	X		| h, hh, l, ll	| 0-+s	|
**
** Bonuses :
**	conversions:	eE, fF, gG, aA, n
**	flags:			*, %, L, '
**	new flags:
**		%b:		binary
**		%r:		non-printable characters
**		%k:		date in ISO format
**	colors, fd, i td..
*/

t_format		*initial()
{
	t_format	*frmt;

	frmt = (t_format *)ft_memalloc(sizeof(t_format));
	frmt->conv = -1;
	frmt->flags = 0;
	frmt->width = 0;
	frmt->precision = -1;
	frmt->lenght = 0;
	return (frmt);
}

static char		*forward(t_format *format_struct, va_list args)
{
	static char	*(*p[17])();

	p[0] = flg_char;
	p[1] = flg_char;
	p[2] = flg_str;
	p[3] = flg_str;
	p[4] = flg_percent;
	p[5] = flg_int;
	p[6] = flg_int;
	p[7] = flg_int;
	p[8] = flg_u;
	p[9] = flg_u;
	p[10] = flg_box;
	p[11] = flg_box;
	p[12] = flg_box;
	p[13] = flg_box;
	p[14] = flg_box;
	p[15] = flg_box;
	p[16] = flg_pointer;
	if (format_struct->conv != -1)
		return (p[format_struct->conv](format_struct, args));
	return (0);
}

static char		*parser(const char **format, va_list args, size_t *len)
{
	t_format	*format_struct;
	char		*ret;

	format_struct = initial();
	parse_flags(format, format_struct);
	parse_width_precis(format, format_struct);
	parse_size_flag(format, format_struct);
	format_struct->conv = chars_conv(format);
	ret = forward(format_struct, args);
	if (ret)
		*len = (size_t)format_struct->width;
	free(format_struct);
	return (ret);
}

static size_t	create_list(t_list **lst, const char *format, va_list args)
{
	char		*new;
	size_t		len;
	size_t		total_len;

	total_len = 0;
	while (format && *format)
	{
		if (*format == '%')
		{
			format++;
			new = parser(&format, args, &len);
			if (!new)
				continue ;
			len = ft_strlen(new);
		}
		else
		{
			len = ft_dstrlen(format, '%');
			new = ft_strndup(format, len);
			format += len;
		}
		total_len += len;
		ft_lstadd_tail(lst, ft_lstinit(new, len));
	}
	return (total_len);
}

int				ft_printf(const char *format, ...)
{
	va_list		args;
	t_list		*strs;
	size_t		total_len;

	va_start(args, format);
	strs = 0;
	total_len = create_list(&strs, format, args);
	ft_lstiter(strs, ft_lstputstr_len);
	va_end(args);
	return (total_len);
}
