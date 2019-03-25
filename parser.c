/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:43:01 by bogoncha          #+#    #+#             */
/*   Updated: 2019/03/25 15:37:54 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** The number of the character in the 'flags' string
** represents the index of their function in the
** function pointer
*/
int converion_chars(char **format)
{
	const char *flags;
    char *index;

	flags = "sSpdDioOuUxXcC%";
	if (index = ft_strchr(flags, **format))
    {
        (*format)++;
		return (index - flags);
    }
	return (-1);
}

int field_width(char **format)
{
	int width;

	width = -1;
	if (ft_isdigit(**format))
	{
		width = ft_atoi(*format);
		*format += ft_getnbsize(width);
	}
	return (width);
}

/*
** The position of the characters in the flag string
** represent the index of their bitin the ret variable.
*/
int flag_chars(char **format)
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
	return (ret);
}