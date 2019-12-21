/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 01:55:58 by nrochard          #+#    #+#             */
/*   Updated: 2019/12/21 02:04:26 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_letter(char *s, t_list *l)
{
	int i;
	int size;

	size = l->nb_zero;
	i = 0;
	if (s == NULL)
		return ;
	if (l->sign == 0)
	{
		while (s[i] != '\0' && size > 0)
		{
			write(1, &s[i], 1);
			size--;
			l->count_print++;
			i++;
		}
	}
	else if (l->sign == 1)
	{
		while (s[i] != '\0')
		{
			write(1, &s[i], 1);
			l->count_print++;
			i++;
		}
	} 
}

void	ft_putstr_letter2(char *s, t_list *l)
{
	int i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		l->count_print++;
		i++;
	}
}

void	ft_putstr_null(char *s, int fd, t_list *l)
{
	int i;
    (void)fd;
	i = 0;
	if (s == NULL)
	{
		s = "(null)";
	}
	while (s[i] != '\0')
	{
        write(1, &s[i], 1);

        l->count_print++;
		i++;
	}
}