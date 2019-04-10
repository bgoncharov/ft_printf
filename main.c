#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

int	main(void)
{
	int		i;

	i = 99;
	
	ft_printf("|%.5u|, 99\n", i);
	ft_printf("|%.0u|, 99\n", i);
	ft_printf("|%.u|, 0\n", 0);
	ft_printf("|%7.5u|, 99\n", i);
	ft_printf("|%7.0u|, 99\n", i);
	ft_printf("|%7.u|, 0\n", 0);
	ft_printf("|%-7.5u|, 99\n", i);
	ft_printf("|%0+7.5u|, 99\n", i);
	ft_printf("|% 07.0u|, 99\n", i);
	ft_putchar('\n');
	ft_printf("|%-07.u|, 0\n", 0);
	ft_printf("|%-07.d|, 0\n", 0);
	ft_printf("|%+07.d|, 0\n", 0);
	ft_printf("|%-+07.d|, 0\n", 0);
	ft_printf("|% 07.d|, 0\n", 0);
	printf("|%+07.d|, 0\n", 0);
	printf("|% 07.d|, 0\n", 0);
	ft_putchar('\n');
	ft_printf("|%08u|\n", i);
	ft_printf("|%02u|\n", i);
	ft_printf("|%01u|\n", i);
	ft_printf("|%08.5u|\n", i);
	ft_printf("|%-8.5u|\n", i);
	ft_printf("|%08.5u|\n", -i);
	ft_printf("|%-8.5u|\n", -i);
	ft_printf("|%8.9u|\n", -i);
	ft_printf("|%-8.9u|\n", i);
	ft_printf("|%02.u|\n", i);
	ft_printf("|%01.u|\n", 0);
	ft_printf("|%08u|\n", -i);
	ft_printf("|%08.5u|\n", -i);
	ft_printf("|%.5u|, 99\n", i);
	ft_printf("|%.0u|, 99\n", i);
	ft_printf("|%.u|, 0\n", 0);
	ft_printf("|%7.5u|, 99\n", i);
	ft_printf("|%7.0u|, 99\n", i);
	ft_printf("|%7.u|, 0\n", 0);
	ft_printf("|%-7.5u|, 99\n", i);
	ft_printf("|%0+7.5u|, 99\n", i);
	ft_printf("|% 07.0u|, 99\n", i);
	ft_printf("|%-07.u|, 0\n", 0);
	return (0);
}
