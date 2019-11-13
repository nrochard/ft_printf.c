
#include "ft_printf.h"

int main()
{
	// char *s = "salut les copains";
	// printf("true = [%s]\n", s);
	printf("true = [%10d]\n", 9);
    ft_printf("%10d", 9);
    
	return (0);
}