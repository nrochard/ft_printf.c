/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 11:14:12 by nrochard          #+#    #+#             */
/*   Updated: 2019/12/21 14:24:59 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	search_modulo(t_list *l)
{
	if (l->check_point == 1 || l->check_point == 0)
	{
		if (l->check_space == 1)
			display_precision_modulo(l);
		else
			display_precision_char(l);
	}
}

void	search_char(t_list *l)
{
	if (l->check_point == 1 || l->check_point == 0)
		display_precision_char(l);
}

void	search_number2(t_list *l)
{
	if (l->check_dash == 1)
	{
		if (l->check_space == 0)
			search_flag6(l);
		else if (l->check_space == 1)
			search_flag7(l);
	}
	else if (l->check_dash == 0)
	{
		if (l->check_space == 0)
			search_flag8(l);
		else if (l->check_space == 1)
			search_flag10(l);
	}
}

void	search_number(t_list *l)
{
	if (l->check_point == 0)
	{
		if (l->check_dash == 1)
		{
			if (l->check_space == 1)
				search_flag2(l);
			else if (l->check_space == 0)
				search_flag3(l);
		}
		else if (l->check_dash == 0)
			search_flag4(l);
	}
	else if (l->check_point == 1)
		search_number2(l);
}

void	search_string(t_list *l)
{
	if (l->check_point == 0)
		search_flag11(l);
	else if (l->check_point == 1)
	{
		if (l->check_dash == 1)
			search_flag12(l);
		else if (l->check_dash == 0)
		{
			if (l->check_space == 0)
			{
				if (l->check_zero == 0)
				{
					search_flag13(l);
				}
				else if (l->check_zero == 1)
				{
					if (l->nb_space != 0 && l->nb_zero == 0)
						display_precision_with_dash_letter(l);
				}
			}
			else if (l->check_space == 1 && l->check_zero == 0 &&
				l->nb_space == 0 && l->nb_zero != 0)
				display_precision_letter(l);
		}
	}
}
