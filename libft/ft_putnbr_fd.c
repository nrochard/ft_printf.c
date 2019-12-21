/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:59:11 by nrochard          #+#    #+#             */
/*   Updated: 2019/12/21 14:19:53 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd, t_list *l)
{
	int nb;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	nb = n;
	if (n < 0)
	{
		nb = -n;
		ft_putchar_fd('-', fd, l);
	}
	if (nb < 10)
		ft_putchar_fd((nb + '0'), fd, l);
	else
	{
		ft_putnbr_fd((nb / 10), fd, l);
		ft_putchar_fd((nb % 10 + '0'), fd, l);
	}
}
