/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 16:30:15 by nrochard          #+#    #+#             */
/*   Updated: 2020/01/13 20:07:57 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		nb;
	long	sign;

	i = 0;
	nb = 0;
	sign = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (sign == 1)
		return (-nb);
	return (nb);
}

char	*ft_itoa(int n, t_list *l)
{
	long	nb;
	long	nb2;
	char	*str;
	int		count;

	nb = n;
	count = 0;
	str = NULL;
	if (n == 0)
		return (ft_manage_zero(l));
	if (n < 0)
	{
		l->negative = 1;
		nb = nb * -1;
	}
	nb2 = nb;
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	str = manage_nb(count, nb2);
	return (str);
}

void	ft_putchar_fd(char c, int fd, t_list *l)
{
	write(fd, &c, 1);
	l->count_print++;
}

void	reverse_stock(t_list *l)
{
	char	*tmp;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(l->stock);
	tmp = malloc(sizeof(char) * (size + 1));
	while (size > 0)
	{
		tmp[i] = l->stock[size - 1];
		i++;
		size--;
	}
	tmp[i] = '\0';
	free(l->stock);
	l->stock = ft_strdup(tmp);
	free(tmp);
}

void	ft_putnbr_fd(int n, int fd, t_list *l)
{
	int nb;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		l->count_print += 11;
		return ;
	}
	nb = n;
	if (n < 0)
	{
		nb = -n;
		ft_putchar_fd('-', fd, l);
	}
	if (nb < 10)
		ft_putchar_fd((nb + '0'), fd, l);
	else
	{
		ft_putnbr_fd((nb / 10), fd, l);
		ft_putchar_fd((nb % 10 + '0'), fd, l);
	}
}
