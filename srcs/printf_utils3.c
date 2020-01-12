/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 16:34:46 by nrochard          #+#    #+#             */
/*   Updated: 2020/01/12 18:01:11 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd, t_list *l)
{
	int i;

	(void)fd;
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

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (src == NULL)
		return (ft_strdup("(null)"));
	while (src[i] != '\0')
		i++;
	len = i;
	i = 0;
	if (!(dest = malloc(sizeof(char) * len + 1)))
		return (0);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_strlen(const char *str)
{
	int a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}
