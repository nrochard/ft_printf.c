
#include "ft_printf.h"

int main()
{

	// printf("true = [%s]\n", s);
	// printf("coucou %-8.12d amis %s\n", 9, "d'angers");
    printf("coucou %10d amis %s\n", 2780, "d'angers");
    ft_printf("coucou %10d amis %s\n", 2780, "d'angers");
    
    // char *s = "salut les copains";
    // printf("true = [%10.24]\n", s);
    // ft_printf("%s", s);
    
	return (0);
}