/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_flag1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 02:39:37 by nrochard          #+#    #+#             */
/*   Updated: 2019/12/21 02:41:43 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void display_space(t_list *l)
{
	l->nb_space = l->nb_space - ft_strlen(l->stock);
	if (l->negative == 1)
		l->nb_space--;
	while (l->nb_space > 0)
	{
		ft_putchar(' ', l);
		l->nb_space--;
	}
	if (l->negative == 1)
		ft_putchar('-', l);
	ft_putstr_fd(l->stock, 1, l);
}

void display_space_with_dash(t_list *l)
{
	if (l->negative == 1)
	{
		ft_putchar('-', l);
		l->nb_space = l->nb_space - (ft_strlen(l->stock) + 1);
	}
	else
		l->nb_space = l->nb_space - ft_strlen(l->stock);
	ft_putstr_fd(l->stock, 1, l);
	while (l->nb_space > 0)
	{
		ft_putchar(' ', l);
		l->nb_space--;
	}
}

void display_zero2(t_list *l)
{
	if (l->negative == 1)
	{
		ft_putchar('-', l);
		l->nb_zero--;
	}	
	l->nb_zero = l->nb_zero - ft_strlen(l->stock) + 1;
	while (l->nb_zero > 0)
	{
		ft_putchar('0', l);
		l->nb_zero--;
	}
	ft_putstr_fd(l->stock, 1, l);
}

void display_zero(t_list *l)
{
	l->nb_space = l->nb_space - ft_strlen(l->stock);
	if (l->negative == 1)
	{
		ft_putchar('-', l);
		l->nb_space--;		
	}
	while (l->nb_space > 0)
	{
		ft_putchar('0', l);
		l->nb_space--;
	}
	ft_putstr_fd(l->stock, 1, l);
}