/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:43:01 by bogoncha          #+#    #+#             */
/*   Updated: 2019/03/25 21:11:16 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** The number of the character in the 'flags' string
** represents the index of their function in the
** function pointer
*/
int conversion_chars(char **format)
{
	const char *flags;
    char *index;

	flags = "sSpdDioOuUxXcC%";
	if ((index = ft_strchr(flags, **format)))
    {
        (*format)++;
		return (index - flags);
    }
	return (-1);
}

void width_precision(char **format, t_format *fmt_struct)
{
	if (ft_isdigit(**format))
	{
		fmt_struct->width = ft_atoi(*format);
		*format += ft_getnbsize(fmt_struct->width);
	}
	if (**format == '.')
	{
		++(*format);
		fmt_struct->precision = ft_atoi(*format);
		while (ft_isdigit(**format))
			++(*format);
	}
}

/*
** The position of the characters in the flag string
** represent the index of their bitin the ret variable.
*/
void flag_chars(char **format, t_format *fmt_struct)
{
	const char *flags;
	int ret;

	flags = "#0-+ ";
	ret = 0;
	while (ft_strchr(flags, **format))
	{
        ret = ret | (1 << (ft_strchr(flags, **format) - flags));
		(*format)++;
	}
    ret = ((ret & 0x6) == 0x6 ? (ret ^ 0x2) : ret);
    ret = ((ret & 0x18) == 0x18 ? (ret ^ 0x10) : ret);
	fmt_struct->flags = ret;
}