
#include "ft_printf.h"

int main()
{
	// char *s = "salut les copains";
	// printf("true = [%s]\n", s);
	printf("true = %p\n", "coucou");
    ft_printf("tiens %p voila mon adresse", "coucou");
    
	return (0);
}