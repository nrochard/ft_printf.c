#include "ft_printf.h"

int main()
{

    char *str = "coucou";
    
    printf("%d\n", printf("%p\n", str));
    printf("%d\n", ft_printf("%p\n", str));

    while(1);
}