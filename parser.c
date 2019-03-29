/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:43:01 by bogoncha          #+#    #+#             */
/*   Updated: 2019/03/28 23:36:36 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** The number of the character in the 'flags' string
** represents the index of their function in the
** function pointer
*/
int conversion_chars(const char **format)
{
	const char	*flags;
    char 		*index;

	flags = "cCsSdDioOuUxXp%";
	if (*format && (index = ft_strchr(flags, **format)))
    {
        (*format)++;
		return (index - flags);
    }
	return (-1);
}

/*
** This function will take lenght of the conversion
*/

void get_size_flag(const char **format, t_format *fmt_struct)
{
	const char	*flags;
	char		*index;

	flags = "hHlLjz";
	if (*format && (index = ft_strchr(flags, **format)))
	{
		if (**format == 'h' && *(*format + 1) == 'h')
		{
			fmt_struct->lenght = 'H';
			++(*format);
		}
		else if (**format == 'l' && *(*format + 1) == 'l')
		{
			fmt_struct->lenght = 'L';
			++(*format);
		}
		else
			fmt_struct->lenght = *index;
		++(*format);
	}
}

/*
** Using atoi function grab the number for width and precision
*/
void get_width_precis(const char **format, t_format *fmt_struct)
{ 
	if (*format && ft_isdigit(**format))
	{
		fmt_struct->width = ft_atoi(*(char **)format);
		//*format += ft_getnbsize(fmt_struct->width);
		while (*format && ft_isdigit(**format))
			++(*format);
	}
	if (*format && **format == '.')
	{
		++(*format);
		fmt_struct->precision = ft_atoi(*(char**)format);
		while (*format && ft_isdigit(**format))
			++(*format);
	}
}

/*
** The position of the characters in the flag string
** represent the index of their bitin the ret variable.
*/
void flag_chars(const char **format, t_format *fmt_struct)
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