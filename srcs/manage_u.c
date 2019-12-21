/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 01:52:07 by nrochard          #+#    #+#             */
/*   Updated: 2019/12/21 08:42:48 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_u(unsigned int nb, t_list *l)
{
	if (nb >= 0 && nb <= 4294967295)
		ft_putnbr_u(nb, l);
	else
		ft_putstr_fd("4294967251", 1, l);
}

char	*ft_itoa_u(unsigned int n, t_list *l)
{
	long	nb;
	long	nb2;
	char	*str;
	int		count;

	(void)l;
	nb = n;
	count = 0;
	str = NULL;
	if (n == 0)
		return (ft_manage_zero(l));
	if (n == 0)
		return (ft_strdup("0"));
	nb2 = nb;
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	str = manage_nb(count, nb2);
	return (ft_strdup(str));
}

void	ft_putnbr_u(unsigned n, t_list *l)
{
	if (n < 10)
		ft_putchar((n + '0'), l);
	else
	{
		ft_putnbr_u((n / 10), l);
		ft_putchar((n % 10 + '0'), l);
	}
}

char	*manage_c(int d, t_list *l)
{
	char	*dest;
	char	src[2];
	int		i;

	i = 0;
	src[0] = d;
	src[1] = '\0';
	if (src[0] == '\0')
	{
		if (!(dest = malloc(sizeof(char) * 2)))
			return (0);
		while (i < 2)
		{
			dest[i] = src[i];
			i++;
		}
		l->count_print++;
		return (dest);
	}
	return (ft_strdup(src));
}
