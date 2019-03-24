#include "ft_printf.h"

int main()
{
    char *str;
    int i;

    str = ft_strcpy(ft_strnew(21), "First test string");
    i = 1988;
    ft_printf("String: \"%s\"\nInt: %d\n", str, i);
    return (0);
}