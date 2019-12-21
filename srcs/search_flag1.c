/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_flag1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 10:09:46 by nrochard          #+#    #+#             */
/*   Updated: 2019/12/21 12:03:35 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	search_flag4(t_list *l)
{
	if (l->check_space == 1)
	{
		if (l->check_zero == 0 && l->nb_space != 0 && l->nb_zero == 0)
			display_zero(l);
		else if (l->check_zero == 0 && l->nb_space == 0 && l->nb_zero == 0)
		{
			if (l->negative == 1)
				ft_putchar('-', l);
			ft_putstr_fd(l->stock, 1, l);
		}
	}
	else if (l->check_space == 0)
		display_space(l);
}

void	search_flag3(t_list *l)
{
	if (l->check_zero == 0 && l->nb_space != 0 && l->nb_zero == 0)
		display_space_with_dash(l);
	else if (l->check_zero == 0 && l->nb_space == 0 && l->nb_zero == 0)
	{
		if (l->negative == 1)
			ft_putchar('-', l);
		ft_putstr_fd(l->stock, 1, l);
	}
}

void	search_flag2(t_list *l)
{
	if (l->check_zero == 0 && l->nb_space == 1 && l->nb_zero == 0)
	{
		if (l->negative == 1)
			ft_putchar('-', l);
		ft_putstr_fd(l->stock, 1, l);
	}
	else if (l->check_zero == 0 && l->nb_space != 0 && l->nb_zero == 0)
		display_space_with_dash(l);
	else if (l->check_zero == 0 && l->nb_space == 0 && l->nb_zero == 0)
	{
		if (l->negative == 1)
			ft_putchar('-', l);
		ft_putstr_fd(l->stock, 1, l);
	}
}

void	search_flag1(const char *str, va_list v, t_list *l)
{
	while (str[l->i] && str[l->i] != '.' && which_letter(str, l->i) != 1)
	{
		if (str[l->i] >= '0' && str[l->i] <= '9')
			manage_space(l, str);
		else if (str[l->i] == '*')
			manage_star_space(l, v);
		else
			l->i++;
	}
	if (str[l->i] == '.' && l->i++)
		l->check_point = 1;
	while (str[l->i] && which_letter(str, l->i) != 1)
	{
		if (str[l->i] >= '0' && str[l->i] <= '9')
			manage_zero(l, str);
		else if (str[l->i] == '*')
			manage_star_zero(l, v);
		else
			l->i++;
	}
}

void	search_flag(const char *str, va_list v, t_list *l)
{
	l->i++;
	if (which_letter(str, l->i) == 1)
	{
		what_type(str, l->i, v, l);
		return ;
	}
	if (str[l->i] == '-')
	{
		l->check_dash = 1;
		l->i++;
	}
	search_flag1(str, v, l);
	if (which_letter(str, l->i) == 1)
		l->stock = manage_type(str, l, v);
	if (str[l->i] == 'd' || str[l->i] == 'i' || str[l->i] == 'x' ||
		str[l->i] == 'X' || str[l->i] == 'u' || str[l->i] == 'p')
		search_number(l);
	else if (str[l->i] == 's')
		search_string(l);
	else if (str[l->i] == 'c')
		search_char(l);
	else if (str[l->i] == '%')
		search_modulo(l);
	reset_list(l);
}
