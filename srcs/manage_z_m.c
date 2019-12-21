/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_z_m.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 20:54:38 by nrochard          #+#    #+#             */
/*   Updated: 2019/12/21 11:47:43 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*norm3(t_list *l)
{
	if (l->nb_space == 0)
		return (ft_strdup("0"));
	if (l->nb_zero > 0)
		return (ft_strdup("0"));
	else
		return (ft_strdup(""));
}

char	*norm2(t_list *l)
{
	if (l->check_space == 0)
	{
		if (l->check_zero == 0)
		{
			if (l->nb_space == 0 && l->nb_zero != 0)
				return (ft_strdup("0"));
			if (l->nb_space != 0 && l->nb_zero != 0)
				return (ft_strdup("0"));
		}
	}
	else if (l->check_space == 1)
	{
		if (l->check_zero == 0)
			if (l->nb_space == 0 && l->nb_zero != 0)
				return (ft_strdup("0"));
		if (l->check_zero == 1)
		{
			if (l->nb_zero == 0 && l->nb_space == 0)
				return (ft_strdup("0"));
			else
				return (ft_strdup(""));
		}
	}
	return (ft_strdup(""));
}

char	*ft_manage_zero(t_list *l)
{
	if (l->check_point == 0)
		return (ft_strdup("0"));
	else if (l->check_point == 1)
	{
		if (l->check_dash == 1)
		{
			if (l->check_space == 1)
			{
				if (l->check_zero == 0)
					return (norm3(l));
			}
			else if (l->check_space == 0)
			{
				if (l->check_zero == 0)
					if (l->nb_zero != 0)
						return (ft_strdup("0"));
			}
		}
		else if (l->check_dash == 0)
			return (norm2(l));
	}
	return (ft_strdup(""));
}

char	*manage_modulo(char d)
{
	char	*dest;
	char	src[2];
	int		i;

	i = 0;
	src[0] = d;
	src[1] = '\0';
	if (!(dest = malloc(sizeof(char) * 2)))
		return (0);
	while (i < 2)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
