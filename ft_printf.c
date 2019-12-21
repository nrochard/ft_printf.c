																																												 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 14:38:14 by nrochard          #+#    #+#             */
/*   Updated: 2019/11/13 19:34:51 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int display_precision_with_dash(t_list *l)
{
	if (l->sign == 1)
		display_space_with_dash(l);
	if (l->sign == 0)
	{
			if (l->nb_zero >= ft_strlen(l->stock))
				l->nb_space -= l->nb_zero;
			else
				l->nb_space -= ft_strlen(l->stock);
			l->nb_zero -= ft_strlen(l->stock);
			if (l->negative == 1)
			{
				l->nb_space--;
				ft_putchar_fd('-', 1, l);
			}
			while (l->nb_zero > 0)
			{
				ft_putchar('0', l);
				l->nb_zero--;
			}
			ft_putstr_fd(l->stock, 1, l);
			while (l->nb_space > 0)
			{
				ft_putchar(' ', l);
				l->nb_space--;
			}
	}
	return (0);
}

void display_precision_modulo(t_list *l)
{
	if (l->check_dash == 1)
	{
		if (l->stock[0] == '\0')
			write(1, "\0", 1);
		else
			ft_putstr_fd(l->stock, 1, l);
	}
	l->nb_space -= 1;
	if (l->check_dash == 0)
	{
		while (l->nb_space > 0)
		{
			ft_putchar('0', l);
			l->nb_space--;
		}
	}
	else 
	{
		while (l->nb_space > 0)
		{
			ft_putchar(' ', l);
			l->nb_space--;
		}
	}
	if (l->check_dash == 0)
	{
		if (l->stock[0] == '\0')
			write(1, "\0", 1);
		else
			ft_putstr_fd(l->stock, 1, l);
	}	
}

void    search_flag(const char *str, va_list v, t_list *l)
{
	l->i++;
	if (which_letter(str, l->i) == 1)
	{
		what_type(str, l->i, v, l);
		return ;
	}
	if (str[l->i] == '-')
	{
		l->check_dash = 1;
		l->i++;
	}
	while (str[l->i] && str[l->i] != '.' && which_letter(str, l->i) != 1)
	{
		if (str[l->i] >= '0' && str[l->i] <= '9')
			manage_space(l, str);
		else if (str[l->i] == '*')
			manage_star_space(l, v);
		else
			l->i++;
	}
	if (str[l->i] == '.' && l->i++)
		l->check_point = 1;

	while (str[l->i] && which_letter(str, l->i) != 1)
	{
		if (str[l->i] >= '0' && str[l->i] <= '9')
			manage_zero(l, str);
		else if (str[l->i] == '*')
			manage_star_zero(l, v);
		else
			l->i++;
	}
	if (which_letter(str, l->i) == 1)
		l->stock = manage_type(str, l, v);
	if (str[l->i] == 'd' || str[l->i] == 'i' || str[l->i] == 'x' || str[l->i] == 'X' || str[l->i] == 'u' || str[l->i] == 'p')
	{	
		if (l->check_point == 0)
		{
			if (l->check_dash == 1)
			{
				if (l->check_space == 1)
				{
					if (l->check_zero == 0 && l->nb_space == 1 && l->nb_zero == 0)
					{
						if (l->negative == 1)
							ft_putchar('-', l);
						ft_putstr_fd(l->stock, 1, l);
					}
					else if (l->check_zero == 0 && l->nb_space != 0 && l->nb_zero == 0)
						display_space_with_dash(l);
					else if (l->check_zero == 0 && l->nb_space == 0 && l->nb_zero == 0)
					{
						if (l->negative == 1)
							ft_putchar('-', l);
						ft_putstr_fd(l->stock, 1, l);
					}
				}
				else if (l->check_space == 0)
				{
					if (l->check_zero == 0 && l->nb_space != 0 && l->nb_zero == 0)
						display_space_with_dash(l);
					else if (l->check_zero == 0 && l->nb_space == 0 && l->nb_zero == 0)
					{
						if (l->negative == 1)
							ft_putchar('-', l);
						ft_putstr_fd(l->stock, 1, l);
					}
				}
			}
			else if (l->check_dash == 0)
			{
				if (l->check_space == 1)
				{
					if (l->check_zero == 0 && l->nb_space != 0 && l->nb_zero == 0)
						display_zero(l);
					else if (l->check_zero == 0 && l->nb_space == 0 && l->nb_zero == 0)
					{
						if (l->negative == 1)
							ft_putchar('-', l);
						ft_putstr_fd(l->stock, 1, l);
					}
				}
				else if (l->check_space == 0)
					display_space(l);
			}
		}
		else if ( l->check_point == 1)
		{
			if (l->check_dash == 1)
			{
				if (l->check_space == 0)
				{
					if (l->check_zero == 0)
					{
						if (l->nb_space != 0 && l->nb_zero == 0)
							display_space_with_dash(l);
						else if (l->nb_space != 0 && l->nb_zero != 0)
							display_precision_with_dash(l);
						else if (l->nb_space == 0 && l->nb_zero == 0)
						{
							if (l->negative == 1)
								ft_putchar_fd('-', 1, l);
							ft_putstr_fd(l->stock, 1, l);
						}
						else if (l->nb_space == 0 && l->nb_zero != 0)
						{
							if (l->sign == 1)
							{
								if (l->negative == 1)
									ft_putchar('-', l);
								ft_putstr_fd(l->stock, 1, l);
							}
							else
								display_precision(l);	
						}
					}
					else if (l->check_zero == 1)
					{
						if (l->nb_space != 0 && l->nb_zero == 0)
							display_space_with_dash(l);
						else if (l->nb_space == 0 && l->nb_zero == 0)
						{
							if (l->negative == 1)
								ft_putchar('-', l);
							ft_putstr_fd(l->stock, 1, l);
						}
					}
				}
				else if (l->check_space == 1)
				{
					if (l->check_zero == 0 && l->nb_space == 0 && l->nb_zero == 1)
					{
						if (l->negative == 1)
							ft_putchar('-', l);
						ft_putstr_fd(l->stock, 1, l);
					}
					else if (l->check_zero == 1 && l->nb_space == 0 && l->nb_zero == 0)
					{
						if (l->negative == 1)
							ft_putchar('-', l);
						ft_putstr_fd(l->stock, 1, l);
					}
					else if (l->check_zero == 0 && l->nb_space != 0)
						display_precision_with_dash(l);
					else if (l->check_zero == 1 && l->nb_space != 0)
						display_space_with_dash(l);
					else if (l->check_zero == 0 && l->nb_space == 0)
					{
						if (l->sign == 1)
						{
							if (l->negative == 1)
								ft_putchar('-', l);
							ft_putstr_fd(l->stock, 1, l);
						}
						else
							display_precision(l);	
					}
				}
			}
			else if (l->check_dash == 0)
			{
				if (l->check_space == 0)
				{
					if (l->check_zero == 0)
					{
						if (l->nb_space != 0 && l->nb_zero != 0)
							display_precision(l);
						else if (l->nb_space == 0 && l->nb_zero != 0)
						{
							if (l->sign == 1)
							{
								if (l->negative == 1)
									ft_putchar_fd('-', 1, l);
								ft_putstr_fd(l->stock, 1, l);
							}
							else
								display_precision(l);
						}
						else if (l->nb_space != 0 && l->nb_zero == 0)
							display_precision(l);
						else if (l->nb_space == 0 && l->nb_zero == 0)
						{
							if (l->negative == 1)
									ft_putchar_fd('-', 1, l);
							ft_putstr_fd(l->stock, 1, l);
						}
					}
					else if (l->check_zero == 1)
					{
						if (l->nb_space != 0 && l->nb_zero == 0)
							display_space(l);
						else if (l->nb_space == 0 && l->nb_zero == 0)
						{
							if (l->negative == 1)
									ft_putchar_fd('-', 1, l);
							ft_putstr_fd(l->stock, 1, l);
						}
					}
				}
				else if (l->check_space == 1)
				{
					if (l->check_zero == 0 && l->nb_zero != 0)
					{
						if (l->sign == 0)
						{
							if (l->negative == 1)
								l->nb_space--;
							if (l->nb_zero >= ft_strlen(l->stock))
								l->nb_space -= l->nb_zero;
							else
								l->nb_space -= ft_strlen(l->stock);
							l->nb_zero -= ft_strlen(l->stock);
							while (l->nb_space > 0)
							{
								ft_putchar(' ', l);
								l->nb_space--;
							}
							if (l->negative == 1)
								ft_putchar('-', l);
							while (l->nb_zero > 0)
							{
								ft_putchar('0', l);
								l->nb_zero--;
							}
							ft_putstr_fd(l->stock, 1, l);
						}
						else if (l->sign == 1)
						{
							l->nb_space -= ft_strlen(l->stock);
							if (l->negative == 1)
							{
								ft_putchar('-', l);
								l->nb_space--;
							}
							while (l->nb_space > 0)
							{
								ft_putchar('0', l);
								l->nb_space--;
							}
							ft_putstr_fd(l->stock, 1, l);
						}
						else
							display_zero2(l);
					}
					else if (l->check_zero == 0 && l->nb_zero == 0)
						display_space(l);
					else if (l->check_zero == 1)
						display_precision(l);
				}
			}
		}
	}

	else if (str[l->i] == 's')
	{
		if (l->check_point == 0)
		{
			if (l->check_dash == 0)
			{
				if (ft_strlen(l->stock) >= l->nb_space)
					ft_putstr_fd(l->stock, 1, l);
				else
					display_space_letter(l);
			}
			else if (l->check_dash == 1)
			{
				if (l->nb_space != 0)
					display_space_with_dash_letter(l);
				else
					ft_putstr_fd(l->stock, 1, l);
			}
		}
		else if (l->check_point == 1)
		{
			if (l->check_dash == 1)
			{
				if (l->check_space == 0)
				{
					if (l->check_zero == 0 && l->nb_space != 0)
					{
						if (l->nb_zero == 0)
							display_only_space_letter(l);
						else if (l->nb_zero != 0)
							display_precision_with_dash_letter(l);
					}
					else if (l->check_zero == 1 && l->nb_space != 0 && l->nb_zero == 0)
						display_precision_with_dash_letter(l);
					else if (l->nb_space == 0 && l->sign == 1 && l->nb_zero != 0)
						ft_putstr_fd(l->stock, 1, l);
					else if (l->nb_space == 0 && l->sign == 0 && l->nb_zero != 0)
						display_precision_letter(l);
				}
				else if (l->check_space == 1 && l->nb_zero != 0)
						display_precision_with_dash_letter(l);
			}
			else if (l->check_dash == 0)
			{
				if (l->check_space == 0)
				{
					if (l->check_zero == 0)
					{
						if (l->nb_space != 0 && l->nb_zero != 0)
						{
							if (l->sign == 1)
								l->nb_space -= ft_strlen(l->stock);
							else if (l->nb_zero < (int)ft_strlen(l->stock))
								l->nb_space -= l->nb_zero;
							else
								l->nb_space -= ft_strlen(l->stock);
							display_precision_letter(l);
						}
						else if (l->nb_space == 0 && l->nb_zero != 0)
							display_precision_letter(l);
						else if (l->nb_space != 0 && l->nb_zero == 0)
						{
							l->nb_zero -= ft_strlen(l->stock);
							if (l->nb_zero >= 0)
								l->nb_space = l->nb_space - l->nb_zero;
							display_precision_letter(l);
						}
					}
					else if (l->check_zero == 1)
					{
						if (l->nb_space != 0 && l->nb_zero == 0)
							display_precision_with_dash_letter(l);
					}
				}
				else if (l->check_space == 1 && l->check_zero == 0 && l->nb_space == 0 && l->nb_zero != 0)
					display_precision_letter(l);
			}
		}
	}
	else if (str[l->i] == 'c')
	{
		if (l->check_point == 1 || l->check_point == 0)
			display_precision_char(l);
	}
	else if (str[l->i] == '%')
	{
		if (l->check_point == 1 || l->check_point == 0)
		{
			if (l->check_space == 1)
				display_precision_modulo(l);
			else
				display_precision_char(l);
		}
	}
}
	
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
	// free(l->stock);
}

int     ft_printf(const char *str, ...)
{
	va_list		v;
	t_list		*l;

	va_start (v, str);
	if ((l = create_list()) == 0)
		return (0);
	while (str[l->i] != '\0')
	{
		if (str[l->i] == '%')
		{ 
			search_flag(str, v, l);
			reset_list(l);
		}
		else
		{
			write(1, &str[l->i], 1);
			l->count_print++;
		}
		l->i++;
	}
	if (l->stock)
		free(l->stock);
	free(l);
	return (l->count_print);
}