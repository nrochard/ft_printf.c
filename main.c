
#include "ft_printf.h"

int main()
{
	char *s = "salut les copains";

	// printf("true = [%s]\n", s);
	ft_printf("%s", s);
	return (0);
}