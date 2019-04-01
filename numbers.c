#include "ft_printf.h"

static char *format_nb(t_format *fmt, int nb)
{
	int len;
	char *str;

	len = ft_getnbsize(nb);
	len = ((nb < 0) ? (len - 1) : len);
	if (fmt->precision == 0 && nb == 0)
		len = 0;
	if (fmt->precision != -1)
		{
			if ((fmt->flags & (PLUS | SPACE)) || nb < 0)
				++fmt->precision;
			if (fmt->precision > fmt->width)
				fmt->width = fmt->precision;
		}
	else
	{
		fmt->width = ft_max(fmt->width, len);
		if (((fmt->flags & (PLUS | SPACE)) || nb < 0) && fmt->width == len)
			++fmt->width;
		if (fmt->flags & ZERO)
			fmt->precision = fmt->width;
	}
	str = ft_strinit(fmt->width, ' ');
	ft_putstr("w: ");
	ft_putnbr(fmt->width);
	ft_putstr(", p: ");
	ft_putnbr(fmt->precision);
	ft_putstr(", l: ");
	ft_putnbr(len);
	ft_putstr("	");
	return (str);
}

char *flag_int(t_format *fmt_struct, va_list valist)
{
	char *str;
	int nb;

	nb = va_arg(valist, int);
	str = format_nb(fmt_struct, nb);
	return (str);
}