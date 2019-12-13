/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:36:35 by nrochard          #+#    #+#             */
/*   Updated: 2019/12/12 20:45:55 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_list *l)
{
	write(1, &c, 1);
    l->count_print++;
}

void	ft_putnbr_u(unsigned n, t_list *l)
{

	// if (n == -2147483648)
	// {
	// 	write(fd, "-2147483648", 11);
	// 	return ;
	// }
	if (n < 10)
		ft_putchar((n + '0'), l);
	else
	{
		ft_putnbr_u((n / 10), l);
		ft_putchar((n % 10 + '0'), l);
	}
}

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

char		*ft_itoa_u(unsigned int n, t_list *l)
{
	long	nb;
	long	nb2;
	char	*str;
	int		count;
    (void)l;

	nb = n;
	count = 0;
	str = NULL;
    // if (n == 0)
    //     printf("l->c = %d\n", l->check);
    if (n == 0)
    {
        return(ft_strdup("0"));
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
