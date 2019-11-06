/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:36:35 by nrochard          #+#    #+#             */
/*   Updated: 2019/11/06 18:52:58 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_u(unsigned n)
{

	// if (n == -2147483648)
	// {
	// 	write(fd, "-2147483648", 11);
	// 	return ;
	// }
	if (n < 10)
		ft_putchar((n + '0'));
	else
	{
		ft_putnbr_u((n / 10));
		ft_putchar((n % 10 + '0'));
	}
}

