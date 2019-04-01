#include "libft.h"
#include <stdlib.h>

char	*ft_strinit(size_t size, int c)
{
	char	*s;

	s = (char *)ft_memset(malloc(size + 1), c, size + 1);
	if (s)
		s[size] = '\0';
	return (s);
}