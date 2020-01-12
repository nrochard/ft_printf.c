/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:36:35 by nrochard          #+#    #+#             */
/*   Updated: 2020/01/12 17:29:23 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_list *l)
{
	write(1, &c, 1);
	l->count_print++;
}

char	*manage_nb(int count, long nb2)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = malloc(sizeof(char) * (count + 1))))
		return (NULL);
	str[count] = '\0';
	while (nb2 > 0)
	{
		str[--count] = (nb2 % 10) + '0';
		nb2 = nb2 / 10;
	}
	return (str);
}

int		ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	while (n--)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		++i;
	}
	return (0);
}

int		how_long(int nb_space)
{
	int count;

	count = 0;
	while (nb_space > 0)
	{
		nb_space = nb_space / 10;
		count++;
	}
	return (count);
}

void	put_negative(t_list *l)
{
	if (l->negative == 1)
		ft_putchar('-', l);
	ft_putstr_fd(l->stock, 1, l);
}
