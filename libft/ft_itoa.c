/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:22:24 by nrochard          #+#    #+#             */
/*   Updated: 2019/12/20 18:57:37 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*manage_nb(int count, long nb2)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = malloc(sizeof(char) * (count + 1))))
		return (NULL);
	str[count] = '\0';
	while (nb2 > 0)
	{
		str[--count] = (nb2 % 10) + '0';
		nb2 = nb2 / 10;
	}
	return (str);
}

char		*ft_itoa(int n, t_list *l)
{
	long	nb;
	long	nb2;
	char	*str;
	int		count;

	nb = n;
	count = 0;
	str = NULL;
	if (n == 0)
		return (ft_manage_zero(l));
	if (n < 0)
	{
		l->negative = 1;
		nb = nb * -1;
	}
	nb2 = nb;
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	str = manage_nb(count, nb2);
	return (str);
}
