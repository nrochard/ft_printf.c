/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_flag3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 02:50:11 by nrochard          #+#    #+#             */
/*   Updated: 2019/12/21 02:55:07 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void display_precision_char(t_list *l)
{
	if (l->check_dash == 1)
	{
		if (l->stock[0] == '\0')
			write(1, "\0", 1);
		else
			ft_putstr_fd(l->stock, 1, l);
	}
	l->nb_space -= 1;
	while (l->nb_space > 0)
	{
		ft_putchar(' ', l);
		l->nb_space--;
	}
	if (l->check_dash == 0)
	{
		if (l->stock[0] == '\0')
			write(1, "\0", 1);
		else
			ft_putstr_fd(l->stock, 1, l);
	}	
}

void	display_precision_with_dash_letter(t_list *l)
{
	ft_putstr_letter(l->stock, l);
	if (l->sign == 1 && l->check_dash == 1)
	{
		if (l->nb_space < (int)ft_strlen(l->stock))
			return;
		else
		{
			l->nb_space = l->nb_space - ft_strlen(l->stock);
			while (l->nb_space > 0)
			{
				ft_putchar(' ', l);
				l->nb_space--;
			}
		}
	}
	else if (l->nb_zero >= (int)ft_strlen(l->stock))
	{
		if (l->nb_space > (int)ft_strlen(l->stock))
			l->nb_space = l->nb_space - ft_strlen(l->stock);
		else
				return;
	}
	else if (l->check_zero == 1 && l->check_dash == 1)
	{
		while (l->nb_space > 0)
			{
				ft_putchar(' ', l);
				l->nb_space--;
			}
	}
	else if ((l->nb_space <= l->nb_zero) && (l->nb_space < (int)ft_strlen(l->stock)))
		return;
	else
		l->nb_space = l->nb_space - l->nb_zero;
	while (l->nb_space > 0)
	{
		ft_putchar(' ', l);
		l->nb_space--;
	}
}