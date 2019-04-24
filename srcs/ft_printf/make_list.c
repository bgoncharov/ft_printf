/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:39:56 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/24 11:50:30 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		initial(t_format *frmt)
{
	frmt->conv = 0;
	frmt->flags = 0;
	frmt->width = 0;
	frmt->precision = -1;
	frmt->lenght = 0;
}

static char		*dispatch(int index, t_format *format_struct, va_list args)
{
	static char	*(*p[20])();

	p[0] = flg_char;
	p[1] = flg_char;
	p[2] = flg_str;
	p[3] = flg_wstr;
	p[4] = flg_percent;
	p[5] = flg_int;
	p[6] = flg_int;
	p[7] = flg_int;
	p[8] = flg_uint;
	p[9] = flg_uint;
	p[10] = flg_bin;
	p[11] = flg_oct;
	p[12] = flg_oct;
	p[13] = flg_hex;
	p[14] = flg_hex;
	p[15] = flg_pointer;
	p[16] = flg_float;
	p[17] = flg_float;
	p[18] = flg_scientific;
	p[19] = flg_scientific;
	return (p[index](format_struct, args));
}

static char		*parser(const char **format, va_list args, size_t *len)
{
	t_format	format_struct;
	char		*ret;
	int			index;

	initial(&format_struct);
	ret = 0;
	parse_flags(format, &format_struct);
	parse_width_precis(format, &format_struct, args);
	parse_size_flag(format, &format_struct);
	index = get_conv(format, &format_struct);
	if (index != -1)
	{
		ret = dispatch(index, &format_struct, args);
		if (ret)
			*len = (size_t)format_struct.width;
	}
	return (ret);
}

size_t			create_list(t_list **lst, const char *format, va_list args)
{
	char		*new;
	size_t		len;
	size_t		total_len;

	total_len = 0;
	while (format && *format)
	{
		if (*format == '%')
		{
			++format;
			new = parser(&format, args, &len);
			if (!new)
				continue ;
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

char			*combine_list(t_list *list, int size_of_list)
{
	char		*newstr;
	char		*cur;
	t_list		*lcur;

	newstr = ft_strnew(size_of_list);
	cur = newstr;
	lcur = list;
	while (lcur)
	{
		ft_memcpy((void *)cur, lcur->content, lcur->content_size);
		cur += lcur->content_size;
		lcur = lcur->next;
	}
	return (newstr);
}
