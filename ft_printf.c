/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 14:38:14 by nrochard          #+#    #+#             */
/*   Updated: 2019/11/06 20:19:31 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf.h"

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

void what_type(const char *str, int i, va_list v)
{
    if (str[i] == 's')
		ft_putstr_fd(va_arg(v, char *), 1);
    else if (str[i] == 'd')
        ft_putnbr_fd(va_arg(v, int), 1);
    else if (str[i] == 'c')
        ft_putchar_fd(va_arg(v, int), 1);
    else if (str[i] == 'i')
        ft_putnbr_fd(va_arg(v, int), 1);
    if (str[i] == 'u')
        put_u(va_arg(v, unsigned int));
    if (str[i] == 'p')
        put_p(va_arg(v, int));
    if (str[i] == 'x')
        ft_putnbr_base(va_arg(v, int), "0123456789abcdef");
    if (str[i] == 'X')
        ft_putnbr_base(va_arg(v, int), "0123456789ABCDEF");
}

int    search_flag(const char *str, int i)
{
	int count;
	int nb;
	
	count = 0;
	while (str[i] && (str[i] != 'c' || str[i] != 's' || str[i] != 'p' || str[i] != 'd'
		|| str[i] != 'i' || str[i] != 'u' || str[i] != 'x' || str[i] != 'X'))
	{
		count++;
		i++;
	}
	nb = count;
	i = i - count;
	while (str[i] && (str[i] != 'c' || str[i] != 's' || str[i] != 'p' || str[i] != 'd'
	|| str[i] != 'i' || str[i] != 'u' || str[i] != 'x' || str[i] != 'X'))
	{
		if (str[i] == '-')
		{

		}
		else if (str[i] == '0')
		{

		}
		else if (str[i] == '.')
		{

		}
		i++;
	}
	return (0);
}

int     ft_printf(const char *str, ...)
{
	va_list v;
	int i;
	int count;

	i = -1;
	count = 0;
	va_start (v, str);
	while (str[++i] != '\0')
	{
		if (str[i] == '%')
		{
			if ((search_flag(str, i + 1) == 0))
			{
				what_type(str, (i + 1), v);
			}
			// else
			// {
				
			// }
		}
		else
			write(1, &str[i], 1);
	}
	return (1);
	// return (< 0 si echec)
	// return(nb charac de read si ok sans '\0')
}
