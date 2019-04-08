/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 11:39:12 by bogoncha          #+#    #+#             */
/*   Updated: 2019/04/07 20:24:33 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define SHARP 0x1
# define ZERO 0x2
# define MINUS 0x4
# define PLUS 0x8
# define SPACE 0x10

# define CONV "cCsS%dDiuUbBoOxXp"

typedef struct		s_format
{
	int				conv;
	unsigned char	flags;
	int				width;
	int				precision;
	char			lenght;
}					t_format;

int					ft_printf(const char *format, ...);

/* function pointer functions */
char				*flg_str(t_format *frmt_struct, va_list args);
char				*flg_int(t_format *frmt_struct, va_list args);
char				*flg_percent(t_format *frmt_struct);
char				*flg_char(t_format *frmt_struct, va_list args);

/* parse functions */
int					chars_conv(const char **format);
static char			*parser(const char **format, va_list args, size_t *len);
void				parse_width_precis(const char **format, t_format *frmt_struct);
void				parse_flags(const char **format, t_format *frmt_struct);
void				parse_size_flag(const char **format, t_format *frmt_struct);
static void			add_prec(int prec, char **str);
static void			add_width(int width, char **str, int left);
static void			print_params(t_format ftm_struct);

static char			*num_format(t_format *frmt, long long num, int len);
static void			sign(char *str, t_format *frmt, int num);
static void			repl_zero(char *str, t_format *frmt, int num);
static void			ft_numcpy(long long num, char *str);
static void			append_flags(char *str, t_format *frmt, long long num);
static long long	take_num(char length, va_list args);

char				*flg_box(t_format *frmt, va_list args);
char				*flg_pointer(t_format *frmt, va_list args);
char				*flg_u(t_format *frmt, va_list args);

#endif
