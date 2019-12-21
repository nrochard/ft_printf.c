/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 02:32:40 by nrochard          #+#    #+#             */
/*   Updated: 2019/12/21 02:33:10 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *manage_type(const char *str, t_list *l, va_list v)
{
	if (str[l->i] == 's')
		l->stock = ft_strdup(va_arg(v, char *));	
	else if (str[l->i] == 'd' || str[l->i] == 'i')
	{	
		if (str)
				l->stock = ft_itoa(va_arg(v, int), l);
	}
	else if (str[l->i] == 'c')
		l->stock = manage_c(va_arg(v, int), l);	
	else if (str[l->i] == 'i')
		l->stock = ft_itoa(va_arg(v, int), l);
	else if (str[l->i] == 'u')
		l->stock = ft_itoa_u(va_arg(v, unsigned int), l);
	else if (str[l->i] == 'p')
		put_p(va_arg(v, void*), l);
	else if (str[l->i] == 'x')
		ft_putnbr_base(va_arg(v, unsigned int), "0123456789abcdef", l);	
	else if (str[l->i] == 'X')
		ft_putnbr_base(va_arg(v, unsigned int), "0123456789ABCDEF", l);
	else if (str[l->i] == '%')
		l->stock = manage_modulo('%');	
	return (l->stock);
}

int	which_letter(const char *str, int i)
{
	if (str[i] && (str[i] == 'c' || str[i] == 's' || str[i] == 'p' || str[i] == 'd' ||
		str[i] == 'i' || str[i] == 'u' || str[i] == 'x' || str[i] == 'X' | str[i] == '%'))
		return (1);
	return (0);
}

void what_type2(const char *str, int i, va_list v, t_list *l)
{
	if (str[i] == 'p')
	{
		put_p(va_arg(v, void*), l);
		ft_putstr_fd(l->stock, 1, l);
	}	
	else if (str[i] == 'x')
	{
		ft_putnbr_base(va_arg(v, unsigned int), "0123456789abcdef", l);
		ft_putstr_fd(l->stock, 1, l);
	}	
	else if (str[i] == 'X')
	{
		ft_putnbr_base(va_arg(v, unsigned int), "0123456789ABCDEF", l);	
		ft_putstr_fd(l->stock, 1, l);
	}
	else if (str[i] == '%')
	{
		l->count_print++;
		write(1, "%", 1);
	}	
}

void what_type(const char *str, int i, va_list v, t_list *l)
{
	if (str[i] == 's')
		ft_putstr_null(va_arg(v, char *), 1, l);	
	else if (str[i] == 'd')
		ft_putnbr_fd(va_arg(v, int), 1, l);
	else if (str[i] == 'c')
		ft_putchar_fd(va_arg(v, int), 1, l);
	else if (str[i] == 'i')
		ft_putnbr_fd(va_arg(v, int), 1, l);
	else if (str[i] == 'u')
		put_u(va_arg(v, unsigned int), l);
	else
		what_type2(str, i, v, l);
}