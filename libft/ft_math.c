#include "libft.h"
#include <stdarg.h>

int		ft_max(int a, int b)
{
	return ((a > b) ? a : b);
}

int		ft_min(int a, int b)
{
	return ((a < b) ? a : b);
}

long	ft_abs(long nb)
{
	return (nb < 0 ? (nb * -1) : nb);
}