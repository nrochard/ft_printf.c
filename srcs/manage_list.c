/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 08:14:08 by nrochard          #+#    #+#             */
/*   Updated: 2019/12/21 08:48:15 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*create_list(void)
{
	t_list	*l;

	if ((l = malloc(sizeof(t_list))) == NULL)
		return (0);
	l->check_space = 0;
	l->check_zero = 0;
	l->check_point = 0;
	l->check_dash = 0;
	l->nb_space = 0;
	l->i = 0;
	l->nb_zero = 0;
	l->stock = NULL;
	l->sign = 0;
	l->ret = 0;
	l->negative = 0;
	l->tmp = 0;
	l->count_print = 0;
	return (l);
}

void	reset_list(t_list *l)
{
	l->check_space = 0;
	l->check_zero = 0;
	l->check_point = 0;
	l->check_dash = 0;
	l->nb_space = 0;
	l->nb_zero = 0;
	l->sign = 0;
	l->ret = 0;
	l->tmp = 0;
	l->negative = 0;
	free(l->stock);
}
