/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_flag2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 02:44:53 by nrochard          #+#    #+#             */
/*   Updated: 2019/12/21 02:46:05 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void display_inferior(t_list *l)
{
	if (ft_strncmp(l->stock, "0", ft_strlen(l->stock)) != 0)
		l->nb_zero = l->nb_zero - ft_strlen(l->stock);
	if (l->negative == 1)
		ft_putchar('-', l);
	while (l->nb_zero > 0)
	{	
		ft_putchar('0', l);
		l->nb_zero--;
	}
	if (ft_strncmp(l->stock, "0", ft_strlen(l->stock)) == 0)
		return ;
	else
		ft_putstr_fd(l->stock, 1, l);
}

void display_superior(t_list *l)
{
	if (l->nb_zero >= ft_strlen(l->stock))
		l->nb_space -= l->nb_zero;
	else
		l->nb_space -= ft_strlen(l->stock);
	l->nb_zero -= ft_strlen(l->stock);
	if (l->negative == 1)
		l->nb_space -= 1;
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


int display_precision(t_list *l)
{
	if (l->sign == 1)
		display_space(l);
	else if (l->sign == 0)
	{
		if (l->nb_space <= l->nb_zero)
		{
			display_inferior(l);
			return(0);
		}
		else if (l->nb_space > l->nb_zero)
		{
			display_superior(l);
			return(0);
		}
		if (l->negative == 1)
			ft_putchar_fd('-', 1, l);
		ft_putstr_fd(l->stock, 1, l);
	}
	return(0);
}
