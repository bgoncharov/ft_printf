/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:43:01 by bogoncha          #+#    #+#             */
/*   Updated: 2019/03/31 16:07:09 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_params(t_format fmt_struct)
{
	char *convs;
	char *flags;
	int i;

	convs = "cCsSDioOuUxXp%";
	flags = "#0-+ ";
	i = 0;
	ft_putchar('%');
	if (fmt_struct.flags)
	{
		while (i < 5)
		{
			if (1 << i && fmt_struct.flags)
				ft_putchar(flags[i]);
			i++;
		}
	}
	if (fmt_struct.width)
		ft_putnbr(fmt_struct.width);
	if (fmt_struct.precision != -1)
		{
			ft_putchar('.');
			ft_putnbr(fmt_struct.precision);
		}
	if (fmt_struct.lenght)
		ft_putchar(fmt_struct.lenght);
	ft_putchar(*(convs + fmt_struct.conv));
	ft_putstr(":	");
}

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
		while (*format && ft_isdigit(**format))
			++(*format);
	}
	if (*format && **format == '.')
	{
		++(*format);
		fmt_struct->precision = ft_atoi(*(char**)format);
		while (*format && ft_isdigit(**format))
			++(*format);
		if (fmt_struct->precision < 0)
			fmt_struct->precision = 0;
	}
}

/*
** The position of the characters in the flag string
** represent the index of their bitin the ret variable.
*/
void get_flags(const char **format, t_format *fmt_struct)
{
	const char *flags;
	int ret;
	const char *cur;

	flags = "#0-+ ";
	ret = 0;
	while ((cur = ft_strchr(flags, **format)))
	{
        ret = ret | (1 << (cur - flags));
		(*format)++;
	}
    ret = ((ret & (ZERO | MINUS)) == (ZERO | MINUS) ? (ret ^ ZERO) : ret);
    ret = ((ret & (SPACE | PLUS)) == (SPACE | PLUS) ? (ret ^ SPACE) : ret);
	fmt_struct->flags = ret;
}