
#include "ft_printf.h"

int main()
{

	 int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

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

	// printf("%d\n", printf("%2i, %2d, %2d, %2d, %2d, %2d", i, j, k, l, m, c));
	// printf("%d\n", ft_printf("%2i, %2d, %2d, %2d, %2d, %2d", i, j, k, l, m, c));

	// printf("%d\n", printf("%1i, %1d, %1d, %1d, %1d, %1d", i, j, k, l, m, c));
	// // printf("%d\n", ft_printf("%1i, %1d, %1d, %1d, %1d, %1d", i, j, k, l, m, c));

	// printf("%d\n", printf("%0i, %0d, %0d, %0d, %0d, %0d", i, j, k, l, m, c));
	// printf("%d\n", ft_printf("%0i, %0d, %0d, %0d, %0d, %0d", i, j, k, l, m, c));

	// printf("%d\n", printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j));
	// printf("%d\n", ft_printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j));

	// printf("%d\n", printf("%4i, %4d, %4d, %4d, %4d, %4d", i, j, k, l, m, c));
	// printf("%d\n", ft_printf("%4i, %4d, %4d, %4d, %4d, %4d", i, j, k, l, m, c));

	// printf("%d\n", printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d", i, j, k, l, m, c));
	// printf("%d\n", ft_printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d", i, j, k, l, m, c));

	// printf("%d\n", printf("|%0.d|", 0));
	// printf("%d\n", ft_printf("|%0.d|", 0));

	// 	printf("%d\n", printf("%.0i, %.0d, %.0d, %.0d, %.0d, %.0d", i, j, k, l, m, c));
	// printf("%d\n", ft_printf("%.0i, %.0d, %.0d, %.0d, %.0d, %.0d", i, j, k, l, m, c));

    // printf("%d\n", printf("|%.0i|\n", 0));
    // printf("%d\n", ft_printf("|%.0i|\n", 0));

    // printf("%d\n", printf("%-0i, %-0d, %-0d, %.0d, %0d, %-0d", i, j, k, l, m, c));
	// printf("%d\n", ft_printf("%-0i, %-0d, %-0d, %.0d, %0d, %-0d", i, j, k, l, m, c));

	// printf("%d\n", printf("%-.i, %-.d, %-.d, %-.d, %-.d, %-.d", i, j, k, l, m, c));
    // printf("%d\n", ft_printf("%-.i, %-.d, %-.d, %-.d, %-.d, %-.d", i, j, k, l, m, c));

	// printf("%d\n", printf("%-01i, %-01d, %-01d, %-01d, %-01d, %-01d", i, j, k, l, m, c));
	// printf("%d\n", ft_printf("%-01i, %-01d, %-01d, %-01d, %-01d, %-01d", i, j, k, l, m, c));

    // printf("%d\n", printf("|%-01d|", 123456789));
	// printf("%d\n", ft_printf("|%-01d|", 123456789));

	// printf("%d\n", printf("%*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
	// printf("%d\n", ft_printf("%*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));

	// printf("%d\n", printf("%-.0i, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d", i, j, k, l, m, c));
	// printf("%d\n", ft_printf("%-.0i, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d", i, j, k, l, m, c));
    
	// printf("%d\n", printf("%-i, %-d, %-d, %-d, %-d, %-d", i, j, k, l, m, c));
	// printf("%d\n", ft_printf("%-i, %-d, %-d, %-d, %-d, %-d", i, j, k, l, m, c));

    // 	printf("%d\n", printf("%.i, %.d, %.d, %.d, %.d, %.d", i, j, k, 0, m, c));
	// printf("%d\n", ft_printf("%.i, %.d, %.d, %.d, %.d, %.d", i, j, k, 0, m, c));

    //  printf("%d\n", printf("|%.d|", 0));
	// printf("%d\n", ft_printf("|%.d|", 0));

    // 	printf("%d\n", printf("%-0.0i, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d", i, j, k, l, m, c));
	// printf("%d\n", ft_printf("%-0.0i, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d", i, j, k, l, m, c));

    // 	printf("%d\n", printf("%00i, %00d, %00d, %00d, %00d, %00d", i, j, k, l, m, c));
	// printf("%d\n", ft_printf("%00i, %00d, %00d, %00d, %00d, %00d", i, j, k, l, m, c));

    	printf("%d\n", printf("%-0.1i, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d", i, j, k, l, m, c));
	printf("%d\n", ft_printf("%-0.1i, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d", i, j, k, l, m, c));

    	// printf("%d\n", printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j));
	// printf("%d\n", ft_printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j));


	return (0);
}