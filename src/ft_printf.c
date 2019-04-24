/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 11:39:02 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/23 18:36:50 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int					ft_printf(const char *format, ...)
{
	va_list		args;
	t_list		*strs;
	size_t		total_len;
	char		*combine;

	va_start(args, format);
	strs = 0;
	total_len = create_list(&strs, format, args);
	combine = combine_list(strs, total_len);
	write(1, combine, total_len);
	ft_lstdel(&strs, ft_lstmemdel);
	ft_strdel(&combine);
	va_end(args);
	return (total_len);
}

int					ft_printfd(int fd, const char *format, ...)
{
	va_list		args;
	t_list		*strs;
	size_t		total_len;
	char		*combine;

	va_start(args, format);
	strs = 0;
	total_len = create_list(&strs, format, args);
	combine = combine_list(strs, total_len);
	write(fd, combine, total_len);
	ft_lstdel(&strs, ft_lstmemdel);
	ft_strdel(&combine);
	va_end(args);
	return (total_len);
}

int					ft_sprintf(char **str, const char *format, ...)
{
	va_list		args;
	t_list		*strs;
	size_t		total_len;

	va_start(args, format);
	strs = 0;
	total_len = create_list(&strs, format, args);
	*str = combine_list(strs, total_len);
	ft_lstdel(&strs, ft_lstmemdel);
	va_end(args);
	return (total_len);
}
