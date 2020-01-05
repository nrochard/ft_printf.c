/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 02:13:48 by nrochard          #+#    #+#             */
/*   Updated: 2020/01/04 21:14:10 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_space(t_list *l, const char *str)
{
	if (str[l->i] == '0')
	{
		l->check_space = 1;
		l->i++;
		if (str[l->i] > '0' && str[l->i] <= '9')
		{
			l->nb_space = ft_atoi(&str[l->i]);
			l->ret = how_long(l->nb_space);
			l->i = l->i + l->ret;
			l->i = l->i - 1;
		}
		return ;
	}
	else if (str[l->i] > '0' && str[l->i] <= '9')
	{
		l->nb_space = ft_atoi(&str[l->i]);
	}
	l->ret = how_long(l->nb_space);
	l->i = l->i + l->ret;
}

void	manage_star_space(t_list *l, va_list v)
{
	l->nb_space = va_arg(v, int);
	if (l->nb_space == 0)
		l->check_space = 1;
	else if (l->nb_space < 0)
	{
		l->check_dash = 1;
		l->nb_space = -l->nb_space;
	}
	l->i++;
}

void	manage_zero(t_list *l, const char *str)
{
	if (str[l->i] == '0')
	{
		l->i++;
		if (str[l->i] > '0' && str[l->i] <= '9')
		{
			l->nb_zero = ft_atoi(&str[l->i]);
			l->ret = how_long(l->nb_zero);
			l->i = l->i + l->ret;
		}
		else
			l->check_zero = 1;
	}
	else if (str[l->i] > '0' && str[l->i] <= '9')
	{
		l->nb_zero = ft_atoi(&str[l->i]);
		l->ret = how_long(l->nb_zero);
		l->i = l->i + l->ret;
	}
}

void	manage_star_zero(t_list *l, va_list v)
{
	l->nb_zero = va_arg(v, int);
	if (l->nb_zero == 0)
		l->check_zero = 1;
	else if (l->nb_zero < 0)
	{
		l->sign = 1;
		l->nb_zero = -l->nb_zero;
	}
	l->i++;
}
