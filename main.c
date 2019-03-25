#include "ft_printf.h"

int main()
{
    //char *str;
    int i;

    //str = ft_strcpy(ft_strnew(21), "First test string");
    //i = 1988;
    //ft_printf("String: \"%s\"\nInt: %d\n", str, i);

    i = 23;
    ft_printf("%10dafter d\n", i);
    return (0);
}