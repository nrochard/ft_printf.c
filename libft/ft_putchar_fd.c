/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:30:04 by nrochard          #+#    #+#             */
/*   Updated: 2019/12/21 14:19:58 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putchar_fd(char c, int fd, t_list *l)
{
	write(fd, &c, 1);
	l->count_print++;
}

void		reverse_stock(t_list *l)
{
	char	*tmp;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(l->stock);
	tmp = malloc(sizeof(char) * (size + 1));
	tmp = l->stock;
	l->stock = NULL;
	l->stock = malloc(sizeof(char) * (size + 1));
	tmp[size] = '\0';
	while (size > 0)
	{
		l->stock[i] = tmp[size - 1];
		i++;
		size--;
	}
	l->stock[i] = '\0';
}
