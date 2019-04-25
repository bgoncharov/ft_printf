/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 11:39:12 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/24 21:48:51 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <wchar.h>

# define SHARP 0x1
# define ZERO 0x2
# define MINUS 0x4
# define PLUS 0x8
# define SPACE 0x10

# define CONV "cCsS%dDiuUboOxXpfFeE"

typedef struct		s_format
{
	char			conv;
	unsigned char	flags;
	int				width;
	int				precision;
	char			lenght;
}					t_format;

char				*flg_str(t_format *frmt_struct, va_list args);
char				*flg_int(t_format *frmt, va_list args);
char				*flg_percent(t_format *frmt_struct);
char				*flg_char(t_format *frmt_struct, va_list args);
char				*flg_bin(t_format *frmt, va_list args);
char				*flg_hex(t_format *frmt, va_list args);
char				*flg_oct(t_format *frmt, va_list args);
char				*flg_pointer(t_format *frmt, va_list args);
char				*flg_uint(t_format *frmt, va_list args);
char				*flg_float(t_format *frmt, va_list args);
char				*flg_wstr(t_format *frmt, va_list args);
char				*flg_wchar(t_format *frmt, va_list args);
char				*flg_scientific(t_format *frmt, va_list args);
int					get_conv(const char **format, t_format *frmt_struct);
void				parse_width_precis(const char **format,
		t_format *frmt_struct, va_list args);
void				parse_flags(const char **format, t_format *frmt_struct);
void				parse_size_flag(const char **format, t_format *frmt_struct);
int					ft_printf(const char *format, ...);
int					ft_sprintf(char **str, const char *format, ...);
int					ft_printfd(int fd, const char *format, ...);
char				*combine_list(t_list *list, int size_of_list);
size_t				create_list(t_list **lst, const char *format, va_list args);

#endif
