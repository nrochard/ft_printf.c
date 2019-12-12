/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:26:22 by nrochard          #+#    #+#             */
/*   Updated: 2019/12/12 02:44:28 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static void reverse_stock(t_list *l)
{
	char *tmp;
	int size;
	int i;

	i = 0;
	// printf("size = %d", size);
	size = ft_strlen(l->stock);
	// printf("size = %d\n", size);
	tmp = malloc(sizeof(char) * (size + 1));
	tmp = l->stock;
	l->stock = NULL;
	l->stock = malloc(sizeof(char) * (size + 1));
	tmp[size] = '\0';
	// printf("|||||tmp|||||| = %s\n", tmp);
	while (size > 0)
	{
		l->stock[i] = tmp[size - 1];
		i++;
		size--;
	}
	l->stock[i] = '\0';
}

void	ft_putnbr_base(unsigned int nbr, char *base, t_list *l)
{
	unsigned int	i;
	unsigned int	a;
	int             size;

	i = 0;
	size = 0;
	while (base[i] != '\0')
		i++;
	a = nbr;
	while (a > i)
	{
		a = a / i;
		size++;
	}
	l->stock = malloc(sizeof(char) * (size + 2));
	size = 0;
	while (nbr > i)
	{
		if (nbr < i)
			l->stock[size] = base[nbr];
		else
			l->stock[size] = base[nbr % i];
		size++;
		nbr = nbr / i;
	}
	if (nbr < i)
		l->stock[size] = base[nbr];
	else
		l->stock[size] = base[nbr % i];
	size++;
	l->stock[size] = '\0';
	reverse_stock(l);
}
