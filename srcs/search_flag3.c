/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seach_flag3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 10:09:52 by nrochard          #+#    #+#             */
/*   Updated: 2019/12/21 11:43:35 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	search_flag13(t_list *l)
{
	if (l->nb_space != 0 && l->nb_zero != 0)
	{
		if (l->sign == 1)
			l->nb_space -= ft_strlen(l->stock);
		else if (l->nb_zero < (int)ft_strlen(l->stock))
			l->nb_space -= l->nb_zero;
		else
			l->nb_space -= ft_strlen(l->stock);
		display_precision_letter(l);
	}
	else if (l->nb_space == 0 && l->nb_zero != 0)
		display_precision_letter(l);
	else if (l->nb_space != 0 && l->nb_zero == 0)
	{
		l->nb_zero -= ft_strlen(l->stock);
		if (l->nb_zero >= 0)
			l->nb_space = l->nb_space - l->nb_zero;
		display_precision_letter(l);
	}
}

void	search_flag12(t_list *l)
{
	if (l->check_space == 0)
	{
		if (l->check_zero == 0 && l->nb_space != 0)
		{
			if (l->nb_zero == 0)
				display_only_space_letter(l);
			else if (l->nb_zero != 0)
				display_precision_with_dash_letter(l);
		}
		else if (l->check_zero == 1 && l->nb_space != 0 && l->nb_zero == 0)
			display_precision_with_dash_letter(l);
		else if (l->nb_space == 0 && l->sign == 1 && l->nb_zero != 0)
			ft_putstr_fd(l->stock, 1, l);
		else if (l->nb_space == 0 && l->sign == 0 && l->nb_zero != 0)
			display_precision_letter(l);
	}
	else if (l->check_space == 1 && l->nb_zero != 0)
		display_precision_with_dash_letter(l);
}

void	search_flag11(t_list *l)
{
	if (l->check_dash == 0)
	{
		if (ft_strlen(l->stock) >= l->nb_space)
			ft_putstr_fd(l->stock, 1, l);
		else
			display_space_letter(l);
	}
	else if (l->check_dash == 1)
	{
		if (l->nb_space != 0)
			display_space_with_dash_letter(l);
		else
			ft_putstr_fd(l->stock, 1, l);
	}
}

void	search_flag14(t_list *l)
{
	l->nb_space -= ft_strlen(l->stock);
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

void	search_flag10(t_list *l)
{
	if (l->check_zero == 0 && l->nb_zero != 0)
	{
		if (l->sign == 0)
			search_flag9(l);
		else if (l->sign == 1)
		{
			search_flag14(l);
		}
		else
			display_zero2(l);
	}
	else if (l->check_zero == 0 && l->nb_zero == 0)
		display_space(l);
	else if (l->check_zero == 1)
		display_precision(l);
}
