
#include "ft_printf.h"

int main()
{
    // printf("%s\n", "je t'aime");
    // ft_printf("%s\n", "je t'aime");

    // printf("%d\n", 1234);
    // ft_printf("%d\n", 1234);
    
    // printf("%i\n", 1234);
    // ft_printf("%i\n", 1234);

    // printf("%c\n", 'c');
    // ft_printf("%c\n", 'c');

    // printf("%c\n", 'c');
    // ft_printf("%c\n", 'c');

    // printf("real_ function = [%u]\n", 7890);
    // ft_printf("%u\n", 7890);
    
    // printf("real_ function = [%p]\n", 7890);
    // ft_printf("%p\n", 7890);

    // printf("real_ function = [%x]\n", 7890);
    // ft_printf("%x\n", 7890);

    // printf("real_ function = [%X]\n", 7890);
    // ft_printf("%X\n", 7890);


    // printf("real_ function = [%X] et [%d] et [%s]\n", 7890, 2365447, "vive les chats");
    // ft_printf("%X et %d et %s\n", 7890, 2365447, "vive les chats");

    printf("%d\n", printf("|%-100.45d|\n", 150));
    printf("%d\n", ft_printf("|%-100.45d|\n", 150));

	return (0);
}