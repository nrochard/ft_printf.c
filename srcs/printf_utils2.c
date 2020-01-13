/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 16:30:18 by nrochard          #+#    #+#             */
/*   Updated: 2020/01/13 21:12:37 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reverse_stock_p(t_list *l)
{
	char	*tmp;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(l->stock) + 2;
	tmp = malloc(sizeof(char) * (size + 1));
	tmp[0] = '0';
	tmp[1] = 'x';
	while (size > 0)
	{
		tmp[i + 2] = l->stock[size - 3];
		i++;
		size--;
	}
	tmp[i] = '\0';
	free(l->stock);
	l->stock = ft_strdup(tmp);
	free(tmp);
}

void	ft_putnbr_p(uintmax_t nbr, char *base, t_list *l)
{
	unsigned int	a;
	int				size;

	size = 0;
	if (nbr == 0)
		l->stock = ft_manage_zero(l);
	else
	{
		a = nbr;
		while (a > 0 && ++size)
			a = a / 16;
		l->stock = malloc(sizeof(char) * (size + 2));
		size = 0;
		while (nbr > 0)
		{
			if (nbr < 16)
				l->stock[size] = base[nbr];
			else
				l->stock[size] = base[nbr % 16];
			size++;
			nbr = nbr / 16;
		}
		l->stock[size] = '\0';
		reverse_stock_p(l);
	}
}

void	end_ft_putnbr_base(unsigned int nbr, int size, char *base, t_list *l)
{
	if (nbr < 16)
		l->stock[size] = base[nbr];
	else
		l->stock[size] = base[nbr % 16];
	size++;
	l->stock[size] = '\0';
	reverse_stock(l);
}

void	ft_putnbr_base(unsigned int nbr, char *base, t_list *l)
{
	unsigned int	a;
	int				size;

	size = 0;
	if (nbr == 0)
		l->stock = ft_manage_zero(l);
	else
	{
		a = nbr;
		while (a > 0 && ++size)
			a = a / 16;
		l->stock = malloc(sizeof(char) * (size + 2));
		size = 0;
		while (nbr >= 16)
		{
			if (nbr < 16)
				l->stock[size] = base[nbr];
			else
				l->stock[size] = base[nbr % 16];
			size++;
			nbr = nbr / 16;
		}
		end_ft_putnbr_base(nbr, size, base, l);
	}
}
