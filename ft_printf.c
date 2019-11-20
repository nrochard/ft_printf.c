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
	

void	display_3(t_list *l)
{
	// printf("space= %d\n", l->nb_space);

	if (l->nb_space > l->nb_zero)
	{
		if (l->nb_zero > (int)ft_strlen(l->stock))
			l->nb_space = l->nb_space - l->nb_zero;
		else
			l->nb_space = l->nb_space - ft_strlen(l->stock);
			while (l->nb_space > 0)
			{
				ft_putchar(' ');
				l->nb_space--;
			}
		l->nb_zero = l->nb_zero - ft_strlen(l->stock);
			while (l->nb_zero > 0)
			{
				ft_putchar('0');
				l->nb_zero--;
			}
	}

	else if (l->nb_space <= l->nb_zero)
	{
		// printf("stock= %s\n", l->stock);
		l->nb_zero = l->nb_zero - ft_strlen(l->stock);
			while (l->nb_zero > 0)
			{
				ft_putchar('0');
				l->nb_zero--;
			}
	}
}

int display_2(const char *str, t_list *l)
{
	l->nb_zero = l->nb_zero - l->ret;
	while (l->nb_zero > 0)
	{
		ft_putchar('0');
		l->nb_zero--;
	}
	return (l->i);

}

void display_space(t_list *l)
{
	l->nb_space = l->nb_space - ft_strlen(l->stock);
	// printf("space = %d", l->nb_space);
	while (l->nb_space != 0)
	{
		ft_putchar(' ');
		l->nb_space--;
	}
}
void    put_u(unsigned int nb)
{
	if (nb >= 0 && nb <= 4294967295)
	{
	   ft_putnbr_u(nb);
	}    
	else
		ft_putstr_fd("4294967251", 1);
}

void    put_p(int s)
{
	write(1, "0x10", 4);
	ft_putnbr_base(s, "0123456789abcdef");
}

int	which_letter(const char *str, int i)
{
	if (str[i] && (str[i] == 'c' || str[i] == 's' || str[i] == 'p' || str[i] == 'd'
		|| str[i] == 'i' || str[i] == 'u' || str[i] == 'x' || str[i] == 'X'))
		return (1);
	else
		return (0);
}

void what_type(const char *str, int i, va_list v)
{
	// printf("let recu = %c\n", str[i]);
	if (str[i] == 's')
		ft_putstr_fd(va_arg(v, char *), 1);
	else if (str[i] == 'd')
	ft_putnbr_fd(va_arg(v, int), 1);
	else if (str[i] == 'c')
		ft_putchar_fd(va_arg(v, int), 1);
	else if (str[i] == 'i')
		ft_putnbr_fd(va_arg(v, int), 1);
	else if (str[i] == 'u')
		put_u(va_arg(v, unsigned int));
	else if (str[i] == 'p')
		put_p(va_arg(v, int));
	else if (str[i] == 'x')
		ft_putnbr_base(va_arg(v, int), "0123456789abcdef");
	else if (str[i] == 'X')
		ft_putnbr_base(va_arg(v, int), "0123456789ABCDEF");		
}

char *manage_type(const char *str, int i, va_list v, char *stock)
{
	if (str[i] == 's')
	{
		stock = (va_arg(v, char *));
		return (stock);
	}
	else if (str[i] == 'd')
	{
		stock = ft_itoa(va_arg(v, int));
		return (stock);
	}
	else if (str[i] == 'c')
	{
		stock = ft_itoa(va_arg(v, int));
		return (stock);
	}
	else if (str[i] == 'i')
	{
		stock = ft_itoa(va_arg(v, int));
		return (stock);
	}
	else if (str[i] == 'u')
	{
		stock = ft_itoa(va_arg(v, int));
		return (stock);
	}
	else if (str[i] == 'p')
		put_p(va_arg(v, int));
	else if (str[i] == 'x')
		ft_putnbr_base(va_arg(v, int), "0123456789abcdef");
	else if (str[i] == 'X')
		ft_putnbr_base(va_arg(v, int), "0123456789ABCDEF");

	return (stock);
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
	l->ret = 0;
	return (l);
}

int    search_flag(const char *str, va_list v)
{
	t_list *l;

	if ((l = create_list()) == 0)
		return (0);	
	if (which_letter(str, l->i) == 1)
	{
		// printf("ici = %c\n", str[i]);
		what_type(str, l->i, v);
		return (1);
	}
	else
	{
		while (which_letter(str, l->i) == 0)
		{
			// printf("qui es tu toi = %c\n", str[i]);
			if (str[l->i] == '-')
				l->check = 1;
			else if (str[l->i] == '0')
			{	
				ft_putstr_fd(l->stock, 1);
				l->check = 2;
				if (str[l->i + 1] > '0' && str[l->i + 1] <= '9')
				{
					l->nb_zero = ft_atoi(&str[l->i + 1]);
					l->ret = how_long( l->nb_zero);
					l->i = l->i + l->ret;
					l->i++;
					break;
				}
			}
			else if (str[l->i] == '.')
			{	
				l->check =  l->check + 3;
				if (str[l->i + 1] == '*')
					 l->nb_zero = va_arg(v, int);
				else if (str[l->i + 1] > '0' && str[l->i + 1] <= '9')
				{
					l->nb_zero = ft_atoi(&str[l->i + 1]);
					// printf("zero= %d\n", l->nb_zero);
					l->ret = how_long( l->nb_zero);
					l->i = l->i + l->ret;
					l->i++;
					// printf("ret = %d\n", l->i);
					break;
				}
			}
			else if (str[ l->i] > '0' && str[l->i] <= '9')
			{
				l->check = 0;
				l->nb_space = ft_atoi(&str[l->i]);
				l->ret = how_long(l->nb_space);
				// printf("ret = %d", l->ret);
				l->i = l->i + l->ret;
			}
		}
		if (which_letter(str, l->i) == 1)
		{
			// printf("SSSSSSSS\n");
			// printf("qui es tu toi = %c\n", str[l->i]);
			l->stock = manage_type(str, l->i, v, l->stock);
		}
		// printf("qui es tu toi = %c\n", str[l->i]);
		if (l->check == 3)
		{
			display_3(l);
			ft_putstr_fd(l->stock, 1);
		}
		if (l->check == 2)
		{
			printf("ici");
			l->i = display_2(str, l);
			ft_putstr_fd(l->stock, 1);
		}
		if (l->check == 0)
		{
			display_space(l);
			ft_putstr_fd(l->stock, 1);
		}
		
	}	
	// printf("ret = %d\n", ret);
	return (l->i + 1);
}
	

int     ft_printf(const char *str, ...)
{
	va_list v;
	int i;
	int count_print;
	int ret = 0;

	i = 0;
	count_print = 0;
	va_start (v, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			// printf("j'envoi quoi = %s\n", &str[i + 1]);
			ret = (search_flag(&str[i + 1], v));
			
			i = i + ret;
			
			// printf("what return = %d\n", ret);
			// printf("str[i] = %c\n", str[i]);
		}
		else
		{
			write(1, &str[i], 1);
			count_print++;
		}
		// printf("i = %d\n", i);
		i++;
	}
	return (1);
}
