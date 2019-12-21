/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 14:38:14 by nrochard          #+#    #+#             */
/*   Updated: 2019/12/21 11:29:08 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		v;
	t_list		*l;

	va_start(v, str);
	if ((l = create_list()) == 0)
		return (0);
	while (str[l->i] != '\0')
	{
		if (str[l->i] == '%')
		{
			search_flag(str, v, l);
		}
		else
		{
			write(1, &str[l->i], 1);
			l->count_print++;
		}
		l->i++;
	}
	free(l);
	return (l->count_print);
}
