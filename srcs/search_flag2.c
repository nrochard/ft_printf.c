/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seach_flag2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 10:09:50 by nrochard          #+#    #+#             */
/*   Updated: 2019/12/21 11:37:19 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	search_flag9(t_list *l)
{
	if (l->negative == 1)
		l->nb_space--;
	if (l->nb_zero >= ft_strlen(l->stock))
		l->nb_space -= l->nb_zero;
	else
		l->nb_space -= ft_strlen(l->stock);
	l->nb_zero -= ft_strlen(l->stock);
	while (l->nb_space > 0)
	{
		ft_putchar(' ', l);
		l->nb_space--;
	}
	if (l->negative == 1)
		ft_putchar('-', l);
	while (l->nb_zero > 0)
	{
		ft_putchar('0', l);
		l->nb_zero--;
	}
	ft_putstr_fd(l->stock, 1, l);
}

void	search_flag8(t_list *l)
{
	if (l->check_zero == 0)
	{
		if (l->nb_space != 0 && l->nb_zero != 0)
			display_precision(l);
		else if (l->nb_space == 0 && l->nb_zero != 0)
		{
			if (l->sign == 1)
				put_negative(l);
			else
				display_precision(l);
		}
		else if (l->nb_space != 0 && l->nb_zero == 0)
			display_precision(l);
		else if (l->nb_space == 0 && l->nb_zero == 0)
			put_negative(l);
	}
	else if (l->check_zero == 1)
	{
		if (l->nb_space != 0 && l->nb_zero == 0)
			display_space(l);
		else if (l->nb_space == 0 && l->nb_zero == 0)
			put_negative(l);
	}
}

void	search_flag7(t_list *l)
{
	if (l->check_zero == 0 && l->nb_space == 0 && l->nb_zero == 1)
		put_negative(l);
	else if (l->check_zero == 1 && l->nb_space == 0 && l->nb_zero == 0)
		put_negative(l);
	else if (l->check_zero == 0 && l->nb_space != 0)
		display_precision_with_dash(l);
	else if (l->check_zero == 1 && l->nb_space != 0)
		display_space_with_dash(l);
	else if (l->check_zero == 0 && l->nb_space == 0)
	{
		if (l->sign == 1)
			put_negative(l);
		else
			display_precision(l);
	}
}

void	search_flag5(t_list *l)
{
	if (l->nb_space != 0 && l->nb_zero == 0)
		display_space_with_dash(l);
	else if (l->nb_space != 0 && l->nb_zero != 0)
		display_precision_with_dash(l);
	else if (l->nb_space == 0 && l->nb_zero == 0)
	{
		if (l->negative == 1)
			ft_putchar_fd('-', 1, l);
		ft_putstr_fd(l->stock, 1, l);
	}
	else if (l->nb_space == 0 && l->nb_zero != 0)
	{
		if (l->sign == 1)
		{
			if (l->negative == 1)
				ft_putchar('-', l);
			ft_putstr_fd(l->stock, 1, l);
		}
		else
			display_precision(l);
	}
}

void	search_flag6(t_list *l)
{
	if (l->check_zero == 0)
		search_flag5(l);
	else if (l->check_zero == 1)
	{
		if (l->nb_space != 0 && l->nb_zero == 0)
			display_space_with_dash(l);
		else if (l->nb_space == 0 && l->nb_zero == 0)
		{
			if (l->negative == 1)
				ft_putchar('-', l);
			ft_putstr_fd(l->stock, 1, l);
		}
	}
}
