/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:43:01 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/07 19:27:46 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		print_params(t_format frmt_struct)
{
	char	*convs;
	char	*flags;
	int		i;

	convs = "cCsSDioOuUxXp%";
	flags = "#0-+ ";
	i = 0;
	ft_putchar('%');
	if (frmt_struct.flags)
	{
		while (i < 5)
		{
			if (1 << i && frmt_struct.flags)
				ft_putchar(flags[i]);
			i++;
		}
	}
	if (frmt_struct.width)
		ft_putnbr(frmt_struct.width);
	if (frmt_struct.precision != -1)
		{
			ft_putchar('.');
			ft_putnbr(frmt_struct.precision);
		}
	if (frmt_struct.lenght)
		ft_putchar(frmt_struct.lenght);
	ft_putchar(*(convs + frmt_struct.conv));
	ft_putstr(":	");
}

int			chars_conv(const char **format)
{
	const char	*types;
	char		*sub;

	types = CONV;
	if (*format && (sub = ft_strchr(types, **format)))
	{
		(*format)++;
		return (sub - types);
	}
	return (-1);
}

void			parse_size_flag(const char **format, t_format *frmt_struct)
{
	const char	*flags;
	char		*sub;

	flags = "hHlLjz";
	if (*format && (sub = ft_strchr(flags, **format)))
	{
		if (**format == 'h' && *(*format + 1) == 'h')
		{
			frmt_struct->lenght = 'H';
			++(*format);
		}
		else if (**format == 'l' && *(*format + 1) == 'l')
		{
			frmt_struct->lenght = 'L';
			++(*format);
		}
		else
			frmt_struct->lenght = *sub;
		++(*format);
	}
}

void			parse_width_precis(const char **format, t_format *frmt_struct)
{
	if (*format && ft_isdigit(**format))
	{
		frmt_struct->width = ft_atoi(*(char **)format);
		while (*format && ft_isdigit(**format))
			++(*format);
	}
	if (*format && **format == '.')
	{
		++(*format);
		frmt_struct->precision = ft_atoi(*(char**)format);
		while (*format && ft_isdigit(**format))
			++(*format);
		if (frmt_struct->precision < 0)
			frmt_struct->precision = 0;
	}
}

void			parse_flags(const char **format, t_format *frmt_struct)
{
	const char	*flags;
	int			ret;
	const char	*cur;

	flags = "#0-+ ";
	ret = 0;
	while ((cur = ft_strchr(flags, **format)))
	{
		ret = ret | (1 << (cur - flags));
		(*format)++;
	}
	ret = ((ret & (ZERO | MINUS)) == (ZERO | MINUS) ? (ret ^ ZERO) : ret);
	ret = ((ret & (SPACE | PLUS)) == (SPACE | PLUS) ? (ret ^ SPACE) : ret);
	frmt_struct->flags = ret;
}
