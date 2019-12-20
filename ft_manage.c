/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 20:54:38 by nrochard          #+#    #+#             */
/*   Updated: 2019/12/20 21:43:20 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_manage_zero(t_list *l)
{
	if (l->check_point == 0)
	{
		if (l->check_dash == 0)
		{
			if (l->check_space == 1)
			{
				if (l->check_zero == 0)
					if (l->nb_space == 0 && l->nb_zero == 0)
						return (ft_strdup("0"));
			}
			else if (l->check_space == 0)
				return (ft_strdup("0"));
		}
		else if (l->check_dash == 1)
		{
			if (l->check_space == 1)
			{
				if (l->check_zero == 0)
					if (l->nb_zero == 0)
						 return (ft_strdup("0"));
			}
			else if (l->check_space == 0)
			{
				if (l->check_zero == 0)
					if (l->nb_zero == 0)
						return (ft_strdup("0"));
			}
		}
	}
	else if (l->check_point == 1)
	{
		if (l->check_dash == 1)
		{
			if (l->check_space == 1)
			{
				if (l->check_zero == 0)
				{
					if (l->nb_space == 0)
						return (ft_strdup("0"));
					if (l->nb_zero > 0)
						return (ft_strdup("0"));
				}
			}
			else if (l->check_space == 0)
			{
				if (l->check_zero == 0)
					if (l->nb_zero != 0)
						return (ft_strdup("0"));
			}
		}
		else if (l->check_dash == 0)
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
				{
					if (l->nb_space == 0 && l->nb_zero != 0)
						return (ft_strdup("0"));
				}
				if (l->check_zero == 1)
				{
					if (l->nb_zero == 0 && l->nb_space == 0)
						return (ft_strdup("0"));
					else
						return (ft_strdup(""));
				}
			}
		}
	}
	return (ft_strdup(""));
}