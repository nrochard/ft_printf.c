																																												 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 14:38:14 by nrochard          #+#    #+#             */
/*   Updated: 2019/11/13 19:34:51 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    put_u(unsigned int nb, t_list *l)
{
	if (nb >= 0 && nb <= 4294967295)
	{
	   ft_putnbr_u(nb, l);
	}    
	else
		ft_putstr_fd("4294967251", 1, l);
}

void    put_p(int s, t_list *l)
{
	write(1, "0x", 2);
	l->count_print = l->count_print + 2;
	ft_putnbr_base(s, "0123456789abcdef", l);
}

void display_inferior(t_list *l)
{
	l->nb_zero = l->nb_zero - ft_strlen(l->stock);
	
	while (l->nb_zero != 0)
	{
		// printf("viddaaaaaa\n");
		ft_putchar('0', l);
		l->nb_zero--;
	}

	ft_putstr_fd(l->stock, 1, l);
}


void display_inferior2(t_list *l)
{
	l->nb_zero = l->nb_zero - ft_strlen(l->stock);
	
	while (l->nb_zero != 0)
	{
		// printf("viddaaaaaa\n");
		ft_putchar('0', l);
		l->nb_zero--;
	}

	ft_putstr_fd(l->stock, 1, l);
}

void display_superior(t_list *l)
{
	l->nb_space = l->nb_space - l->nb_zero;
	l->nb_zero = l->nb_zero - ft_strlen(l->stock);
	
	while (l->nb_space != 0)
	{
		// printf("COUCOU\n");
		ft_putchar(' ', l);
		l->nb_space--;
	}
	// printf ("stock = %s\n", l->stock)'

	while (l->nb_zero != 0)
	{
		// printf("viddaaaaaa\n");
		ft_putchar('0', l);
		l->nb_zero--;
	}

	ft_putstr_fd(l->stock, 1, l);
}


void display_superior2(t_list *l)
{
	l->nb_space = l->nb_space - l->nb_zero;
	l->nb_zero = l->nb_zero - ft_strlen(l->stock);
	
	while (l->nb_zero != 0)
	{
		// printf("viddaaaaaa\n");
		ft_putchar('0', l);
		l->nb_zero--;
	}

	ft_putstr_fd(l->stock, 1, l);

	while (l->nb_space != 0)
	{
		// printf("COUCOU\n");
		ft_putchar(' ', l);
		l->nb_space--;
	}
	// printf ("stock = %s\n", l->stock)'

}

int display_precision_with_dash(t_list *l)
{
	if (l->nb_space <= l->nb_zero)
	{
		display_inferior2(l);
		return(0);
	}
	else if (l->nb_space > l->nb_zero)
	{
		display_superior2(l);
		return(0);
	}
	return(0);
}

int display_precision(t_list *l)
{
	// printf("check = %d\n", l->check);

	if (l->nb_space <= l->nb_zero)
	{
		display_inferior(l);
		return(0);
	}
	else if (l->nb_space > l->nb_zero)
	{
		display_superior(l);
		return(0);
	}	

	// while (l->nb_space != 0)
	// {
	// 	// printf("COUCOU\n");
	// 	ft_putchar(' ', l);
	// 	l->nb_space--;
	// }
	// while (l->nb_zero != 0)
	// {
	// 	ft_putchar('0', l);
	// 	l->nb_zero--;
	// }
	ft_putstr_fd(l->stock, 1, l);
	return(0);
}

void display_space(t_list *l)
{
	// printf("tas quoi en stock= %s\n", l->stock);
	l->nb_space = l->nb_space - ft_strlen(l->stock);
	// printf("strlen = %zu\n", (ft_strlen(l->stock)));
	// printf("nb_space = %d\n", l->nb_space);

	while (l->nb_space > 0)
	{
		// printf("COUCOU\n");
		ft_putchar(' ', l);
		l->nb_space--;
	}
	// printf ("stock = %s\n", l->stock);
	ft_putstr_fd(l->stock, 1, l);
}

void display_zero(t_list *l)
{
	// printf("COUCOU\n");
	l->nb_zero = l->nb_zero - ft_strlen(l->stock);
	// printf("space = %d", l->nb_space);
	while (l->nb_zero != 0)
	{
		ft_putchar('0', l);
		l->nb_zero--;
	}
	// printf("stock = %s\n", l->stock);
	ft_putstr_fd(l->stock, 1, l);
}

void display_dash(t_list *l)
{
	// printf("nb _space22222 = %d\n", l->nb_space);
	ft_putstr_fd(l->stock, 1, l);
	// printf("%s\n", l->stock);
	l->nb_space = l->nb_space - ft_strlen(l->stock);
	while (l->nb_space != 0)
	{
		ft_putchar(' ', l);
		l->nb_space--;
	}
}

char  *manage_c(int d)
{
	char ouss[2];

	ouss[0] = d;
	ouss[1] = '\0';

	return (ft_strdup(ouss));
}  

char *manage_type(const char *str, t_list *l, va_list v)
{
	if (str[l->i] == 's')
		l->stock = (ft_strdup(va_arg(v, char *)));
	else if (str[l->i] == 'd')
	{	
		// printf("ici\n");
		if (str)
		{
			// printf("#######\n");
				l->stock = ft_itoa(va_arg(v, int), l);
		}	
	}	
	else if (str[l->i] == 'c')
	{
		// printf("NONONONOONOONO\n");
		l->stock = manage_c(va_arg(v, int));
		// printf("NONONONOONOONO\n");
	}	
	else if (str[l->i] == 'i')
		l->stock = ft_itoa(va_arg(v, int), l);
	else if (str[l->i] == 'u')
		l->stock = ft_itoa(va_arg(v, int), l);
	else if (str[l->i] == 'p')
		put_p(va_arg(v, int), l);
	else if (str[l->i] == 'x')
	{
		printf("#######\n");
		ft_putnbr_base(va_arg(v, unsigned int), "0123456789abcdef", l);
		printf("999999999\n");
	}	
	else if (str[l->i] == 'X')
		ft_putnbr_base(va_arg(v, unsigned int), "0123456789ABCDEF", l);

	return (l->stock);
}


int how_long(int nb_space)
{
	int count;

	count = 0;
	while (nb_space > 0)
	{
		nb_space = nb_space / 10;
		count++;
	}
	return (count);
}

void    manage_space(t_list *l, const char *str)
{
	l->check = 0;
	l->nb_space = ft_atoi(&str[l->i]);
	// printf("nb _space = %d\n", l->nb_space);
	l->ret = how_long(l->nb_space);
	l->i = l->i + l->ret;
	l->i= l->i - 1;

}


int    manage_zero2(t_list *l, const char *str, va_list v)
{
	// l->i++;
	if (str[l->i] > '0' && str[l->i] <= '9')
	{
		l->nb_zero = ft_atoi(&str[l->i]);
		l->ret = how_long( l->nb_zero);
		l->i = l->i + l->ret - 1;
		// printf("nb _zero = %d", l->nb_zero);
	}
	else if (str[l->i] == '*')
	{
		l->nb_zero = va_arg(v, int);
		if (l->nb_zero <= 0)
		{
			l->nb_space = -l->nb_zero;
			l->check = 3;
		} 
		l->ret = how_long( l->nb_zero);
		// l->i = l->i + 1;
	}
	// else if (str[l->i] == '0')
	// {
	//     // printf("ddddddddd\n");
	// 	l->check = 5;
	// 	// l->i++;
	// }
	// if (l->nb_space == 0)
	// 	l->check = 5;
	return (0);
}

int    manage_zero(t_list *l, const char *str, va_list v)
{
	l->check = 2;
	l->i++;
	if (str[l->i] > '0' && str[l->i] <= '9')
	{
		l->nb_zero = ft_atoi(&str[l->i]);
		l->ret = how_long( l->nb_zero);
		l->i = l->i + l->ret;
	}
	else if (str[l->i] == '*')
	{
		l->nb_zero = va_arg(v, int);
		if (l->nb_zero <= 0)
		{
			l->nb_space = -l->nb_zero;
			l->check = 3;
		} 
		l->ret = how_long( l->nb_zero);
		// l->i = l->i + 1;
	}
	else if (str[l->i] == '0')
	{
		// printf("ddddddddd\n");
		l->check = 5;
		// l->i++;
	}
	if (l->nb_space == 0)
		l->check = 5;
	return (0);
}

int	which_letter(const char *str, int i)
{
	// printf("|||||||||||||||||||||||||||||||||||||\n|%d = %c|\n||||||||||||||||||||||||||\n", i, str[i]);
	if (str[i] && (str[i] == 'c' || str[i] == 's' || str[i] == 'p' || str[i] == 'd' || \
		str[i] == 'i' || str[i] == 'u' || str[i] == 'x' || str[i] == 'X'))
		return (1);
	return (0);
}

void manage_dash(t_list *l, const char *str)
{
	l->i++;
	l->check = 3;
	l->sign = 1;
	l->nb_space = ft_atoi(&str[l->i]);
	// printf("nb _space = %d", l->nb_space);
	l->ret = how_long(l->nb_space);
	l->i = l->i + l->ret - 1;
}



void what_type(const char *str, int i, va_list v, t_list *l)
{
	if (str[i] == 's')
		ft_putstr_fd(va_arg(v, char *), 1, l);	
	else if (str[i] == 'd')
		ft_putnbr_fd(va_arg(v, int), 1, l);
	else if (str[i] == 'c')
		ft_putchar_fd(va_arg(v, int), 1, l);
	else if (str[i] == 'i')
		ft_putnbr_fd(va_arg(v, int), 1, l);
	else if (str[i] == 'u')
		put_u(va_arg(v, unsigned int), l);
	else if (str[i] == 'p')
		put_p(va_arg(v, int), l);
	else if (str[i] == 'x')
	{
		// printf("|||||ici|||||\n");
		ft_putnbr_base(va_arg(v, unsigned int), "0123456789abcdef", l);
	}	
	else if (str[i] == 'X')
		ft_putnbr_base(va_arg(v, unsigned int), "0123456789ABCDEF", l);		
}

int    search_flag(const char *str, va_list v, t_list *l)
{
	// printf("LAAAAAA\n");
	l->i++;
	if (which_letter(str, l->i) == 1)
	{
		what_type(str, l->i, v, l);
		l->i++;
		return (1);
	}
	// printf("FIRST STEP\n");
	while (str[l->i] && which_letter(str, l->i) != 1)
	{
		if (str[l->i] > '0' && str[l->i] <= '9')
		{
			if (l->check == 0)
			{
				manage_space(l, str);
				// printf("nb_space = %d\n", l->nb_space);
			}	
			else if (l->check == 4 || l->check == 7)
			{
				// printf("SECOND STEP\n");
				manage_zero2(l, str, v);
				// printf("nb_zero = %d\n", l->nb_zero);
			}
		}	
		else if (str[l->i] == '0') 
		{
			if (which_letter(str, l->i + 1) == 1)
			{
				// printf("@@@@@@@@@@@\n");
				l->i = l->i + 1;
				l->check = 5;
				break;
			}   
			// printf("WWWWWWWWW\n");
			manage_zero(l, str, v);
		}	
		else if (str[l->i] == '-') 
		{
			// printf("BABAABABAABBAABAB\n");
			manage_dash(l, str);
		}	
		else if (str[l->i] == '.')
		{
			// printf("COUCOUUUU\n");
			l->check = l->check + 4;
		}
		// printf("quel index1 = %d\n", l->i);
		// printf("carac actu = [%c]\n", str[l->i]);
		l->i++;
	}
	// printf("quel index = %d\n", l->i);
	// printf("check = %d\n", l->check);
	// printf("carac actu = [%c]\n", str[l->i]);
	if (which_letter(str, l->i) == 1)
		l->stock = manage_type(str, l, v);
	// printf("stock after take= %s\n", l->stock);	
		// printfxs("check = %d\n", l->check);
   
	if (l->check == 0)
	{
		// printf("QQQQQQQQQQQ\n");
		display_space(l);
	}
	else if (l->check == 2)
		display_zero(l);
	else if (l->check == 3)
	{
		// printf("**********\n");
		display_dash(l);
	}
	else if(l->check == 4){
		display_precision(l);
	}
	else if (l->check == 5)
	{	
			// printf("$$$$$$$$\n");
			ft_putstr_fd(l->stock, 1, l);
	}
	else if(l->check == 7)
	{
		if (l->nb_space == 0 && l->nb_zero == 0)
			ft_putstr_fd(l->stock, 1, l);
		else{
			display_precision_with_dash(l);
		}
	}
	return (l->i++);
}
	
t_list *create_list(void)
{
	t_list *l;

	if ((l = malloc(sizeof(t_list))) == NULL)
		return (0);
	l->check = 0;
	l->nb_space = 0;
	l->i = 0;
	l->nb_zero = 0;
	l->stock = NULL;
	l->sign = 0;
	l->ret = 0;
	l->count_print = 0;
	return (l);
}

void	reset_list(t_list *l)
{
	l->check = 0;
	l->nb_space = 0;
	l->nb_zero = 0;
	l->sign = 0;
	l->ret = 0;
}

int     ft_printf(const char *str, ...)
{
	va_list v;
	t_list *l;
	int ret;

	va_start (v, str);
	if ((l = create_list()) == 0)
		return (0);	
	while (str[l->i] != '\0')
	{
		// printf("qui es tu = %c\n", str[l->i]);
		if (str[l->i] == '%')
		{ 
			// printf("j'envoi quoi = [%s]\n", &str[l->i + 1]);
			// printf("quel i = [%d]\n", l->i);
			l->ret = (search_flag(str, v, l));
			reset_list(l);
			// printf("what return = %d\n", ret);
			// printf("str[i] = %c\n", str[i]);
		}
		else
		{
			write(1, &str[l->i], 1);
			l->i++;
			l->count_print++;
		}
	}
	ret = l->count_print;
	// printf("return = %d\n", l->count_print);
	if (l->stock)
		free(l->stock);
	free(l);
	return (ret);
}