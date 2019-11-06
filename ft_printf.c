/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 14:38:14 by nrochard          #+#    #+#             */
/*   Updated: 2019/11/06 12:59:37 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf.h"

// void put_s(char *s)
// {
//     int i;

//     i = 0;
//     while (s[i] != '\0')
//         i++;
//     write(1, s, i);
// }

void what_type(const char *str, int i, va_list v)
{
    if (str[i] == 's')
		ft_putstr_fd(va_arg(v, char *), 1);
    if (str[i] == 'd')
        ft_putnbr_fd(va_arg(v, int), 1);
    if (str[i] == 'c')
        ft_putchar_fd(va_arg(v, char), 1);
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
			else
			{
				
			}
            break;
		}
		else
			write(1, &str[i], 1);
	}
	return (1);
	// return (< 0 si echec)
	// return(nb charac de read si ok sans '\0')
}
