/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:26:22 by nrochard          #+#    #+#             */
/*   Updated: 2019/12/06 22:24:49 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int		check_base(char *base, int i)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (base[a] != '\0')
	{
		if (base[a] == '+' || base[a] == '-' || base[a] == '\t' ||
				base[a] == '\v' || base[a] == '\f' || base[a] == '\r')
			return (0);
		else
			a++;
	}
	if (i < 2)
		return (0);
	while (base[a] != '\0')
	{
		if (base[a] != base[b])
			b++;
		else
			return (0);
		a++;
	}
	return (i);
}

void	ft_putnbr_base(unsigned int nbr, char *base, t_list *l)
{
	unsigned int	i;
	unsigned int	a;
	int				fail;

	i = 0;
	a = nbr;
	while (base[i] != '\0')
		i++;
	fail = check_base(base, i);
	if (fail == 0)
		return ;
	if (nbr < 0)
	{
		a = -nbr;
		ft_putchar('-', l);
	}
	else
		a = nbr;
	if (a < i)
		ft_putchar(base[a], l);
	else
	{
		ft_putnbr_base(a / i, base, l);
		ft_putchar(base[a % i], l);
	}
}
