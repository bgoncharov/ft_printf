/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:07:57 by bogoncha          #+#    #+#             */
/*   Updated: 2019/03/27 15:41:28 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void print_params(t_format ftm_struct)
{
	printf("flagc: %x\n", ftm_struct.flags);
	printf("width: %d\n", ftm_struct.width);
	printf("precis: %d\n", ftm_struct.precision);
	printf("lenght: %c\n", ftm_struct.lenght);
	printf("conv: %d\n", ftm_struct.conv);
	printf("\n");
}

/*
** correttly cut the string
*/
static void cut_string(int precision, char **str)
{
	int len;
	char *new;

	len = ft_strlen(*str);
	if (len > precision)
	{
		new = ft_strndup(*str, precision);
		*str = new;
	}
}

char *flag_char(t_format *fmt_struct, va_list valist)
{
	char c;

	print_params(*fmt_struct);
	c = (char)va_arg(valist, int);
	if (!c)
		return (ft_strdup("^@"));
	return (ft_strdup(&c));
}

char *flag_string(t_format *fmt_struct, va_list valist)
{
	char *str;

	print_params(*fmt_struct);
	str = va_arg(valist, char *);
	if (!str)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	cut_string(fmt_struct->precision, &str);
	return (str);
}

char *flag_int(t_format *fmt_struct, va_list valist)
{
	print_params(*fmt_struct);
	return (ft_itoa(va_arg(valist, int)));
}

char *flag_percent(t_format *fmt_struct)
{
	print_params(*fmt_struct);
	return (ft_strdup("%"));
}
