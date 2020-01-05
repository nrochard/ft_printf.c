/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 01:47:18 by nrochard          #+#    #+#             */
/*   Updated: 2020/01/04 20:50:39 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_p(void *s, t_list *l)
{
	int			i;
	uintmax_t	nb;

	i = 0;
	if (s == NULL)
	{
		if (l->check_point == 0)
			l->stock = ft_strdup("0x0");
		else
			l->stock = ft_strdup("0x");
		return ;
	}
	nb = (uintmax_t)s;
	if (nb == 0)
		l->stock = ft_strdup("0");
	else
		ft_putnbr_p(nb, "0123456789abcdef", l);
}
