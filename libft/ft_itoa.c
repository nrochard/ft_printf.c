/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:22:24 by nrochard          #+#    #+#             */
/*   Updated: 2019/12/13 02:48:00 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*manage_nb(int count, long nb2, int n)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = malloc(sizeof(char) * (count + 1))))
		return (NULL);
	str[count] = '\0';
	if (n < 0)
		str[0] = '-';
	while (nb2 > 0)
	{
		str[--count] = (nb2 % 10) + '0';
		nb2 = nb2 / 10;
	}
	return (str);
}

char		*ft_itoa(int n, t_list *l)
{
	long	nb;
	long	nb2;
	char	*str;
	int		count;
    (void)l;

	nb = n;
	count = 0;
	str = NULL;
    if (l->check_point == 0 && l->check_dash == 0 && l->check_space == 1 && l->check_zero == 0 && l->nb_space == 0 && l->nb_zero == 0 && n == 0)
    {
        // printf("i=||||||||s||");
        return (ft_strdup("0"));
    }
    else if (l->check_point == 0 && l->check_dash == 1 && l->check_space == 1 && l->check_zero == 0 && l->nb_space == 0 && l->nb_zero == 0 && n == 0)
    {
        // printf("i=||||||||s||");
         return (ft_strdup("0"));
    }
    else if (l->check_point == 0 && l->check_dash == 1 && l->check_space == 1 && l->check_zero == 0 && l->nb_space == 1 && l->nb_zero == 0 && n == 0)
     {
        // printf("i=||||||||s||");
         return (ft_strdup("0"));
    }
    else if ( l->check_point == 0 && l->check_dash == 0 && l->check_space == 0 && l->check_zero == 0 && l->nb_space != 0 && l->nb_zero == 0 && n == 0)
     {
        // printf("i=||||||||s||");
         return (ft_strdup("0"));
    }
    else if (l->check_point == 1 && l->check_dash == 1 && l->check_space == 1 && l->check_zero == 0 && l->nb_space == 0 && l->nb_zero == 1 && n == 0)
    {
        // printf("i=||||||||s||");
         return (ft_strdup("0"));
    }
	if (n < 0)
	{
		nb = nb * -1;
		count++;
	}
	nb2 = nb;
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	str = manage_nb(count, nb2, n);
	return (str);
}
