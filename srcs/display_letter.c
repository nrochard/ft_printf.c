/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_letter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 02:23:03 by nrochard          #+#    #+#             */
/*   Updated: 2019/12/21 09:32:07 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	display_precision_letter(t_list *l)
{
	if (l->nb_space > 0)
	{
		while (l->nb_space > 0)
		{
			ft_putchar(' ', l);
			l->nb_space--;
		}
	}
	ft_putstr_letter(l->stock, l);
}

void	display_only_space_letter(t_list *l)
{
	while (l->nb_space > 0)
	{
		ft_putchar(' ', l);
		l->nb_space--;
	}
}

void	display_space_letter(t_list *l)
{
	l->nb_space -= ft_strlen(l->stock);
	while (l->nb_space > 0)
	{
		ft_putchar(' ', l);
		l->nb_space--;
	}
	ft_putstr_fd(l->stock, 1, l);
}

void	display_space_with_dash_letter(t_list *l)
{
	ft_putstr_letter2(l->stock, l);
	l->nb_space = l->nb_space - ft_strlen(l->stock);
	while (l->nb_space > 0)
	{
		ft_putchar(' ', l);
		l->nb_space--;
	}
}
