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

void    put_u(unsigned int nb, t_list *l)
{
	if (nb >= 0 && nb <= 4294967295)
	   ft_putnbr_u(nb, l); 
	else
		ft_putstr_fd("4294967251", 1, l);
}

void    put_p(void *s, t_list *l)
{
	int i;
	uintmax_t nb;

	i = 0;
	if (s == NULL)
	{
		if (l->check_point == 0)
			l->stock = ft_strdup("0x0");
		else 
			l->stock = ft_strdup("0x");
		return ;
	}	
	nb = (uintmax_t)s;
	if (nb == 0)
		l->stock = ft_strdup("0");
	else
	ft_putnbr_p(nb, "0123456789abcdef", l);
}


void display_space(t_list *l)
{
	
	// printf("tas quoi en stock= '%s'\n", l->stock);
	l->nb_space = l->nb_space - ft_strlen(l->stock);
	// printf("strlen = %zu\n", (ft_strlen(l->stock)));
	// printf("nb_space = %d\n", l->nb_space);
	if (l->negative == 1)
		l->nb_space--;
	while (l->nb_space > 0)
	{
		// printf("COUCOU\n");
		ft_putchar(' ', l);
		l->nb_space--;
	}
	if (l->negative == 1)
	{
		ft_putchar('-', l);
	}
	ft_putstr_fd(l->stock, 1, l);
	// printf ("stock = %s\n", l->stock);
	
}

void display_space_with_dash(t_list *l)
{
	// printf("nb _space22222 = %d\n", l->nb_space);
	if (l->negative == 1)
	{
		ft_putchar('-', l);
		l->nb_space = l->nb_space - (ft_strlen(l->stock) + 1);
	}
	else
		l->nb_space = l->nb_space - ft_strlen(l->stock);
	ft_putstr_fd(l->stock, 1, l);

	while (l->nb_space > 0)
	{
		ft_putchar(' ', l);
		l->nb_space--;
	}
}


void display_inferior(t_list *l)
{
	if (ft_strncmp(l->stock, "0", ft_strlen(l->stock)) != 0)
		l->nb_zero = l->nb_zero - ft_strlen(l->stock);
	if (l->negative == 1)
		ft_putchar('-', l);
	while (l->nb_zero > 0)
	{	
		ft_putchar('0', l);
		l->nb_zero--;
	}
	if (ft_strncmp(l->stock, "0", ft_strlen(l->stock)) == 0)
		return ;
	else
		ft_putstr_fd(l->stock, 1, l);
}

void display_inferior2(t_list *l)
{
	ft_putstr_fd(l->stock, 1, l);
	l->nb_space = -l->nb_space;
	l->nb_space = l->nb_space - ft_strlen(l->stock);
	if (l->negative == 1)
		l->nb_space--;
	while (l->nb_space >= 0)
	{
		ft_putchar(' ', l);
		l->nb_space--;
	}
}

void display_superior(t_list *l)
{
	if (l->nb_zero >= ft_strlen(l->stock))
		l->nb_space -= l->nb_zero;
	else
		l->nb_space -= ft_strlen(l->stock);
	l->nb_zero -= ft_strlen(l->stock);
	if (l->negative == 1)
		l->nb_space -= 1;
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


void display_superior2(t_list *l)
{
	if (l->negative == 1)
	{
		ft_putchar('-', l);
		l->tmp = 1;
	}
	if (l->nb_space < 0)
		l->nb_space = -l->nb_space;
	l->nb_space = l->nb_space - ft_strlen(l->stock);
	l->nb_zero = l->nb_zero - ft_strlen(l->stock) + 1;
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

int display_precision_with_dash(t_list *l)
{
	if (l->sign == 1)
	{
		display_space_with_dash(l);
	}

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
			return(0);
	}
	return (0);
}

void display_precision_char(t_list *l)
{
	if (l->check_dash == 1)
	{
		if (l->stock[0] == '\0')
			write(1, "\0", 1);
		else
			ft_putstr_fd(l->stock, 1, l);
	}	
	
	l->nb_space -= 1;
	while (l->nb_space > 0)
	{
		ft_putchar(' ', l);
		l->nb_space--;
	}
	if (l->check_dash == 0)
	{
		if (l->stock[0] == '\0')
			write(1, "\0", 1);
		else
			ft_putstr_fd(l->stock, 1, l);
	}	
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

int display_precision(t_list *l)
{
	if (l->sign == 1)
		display_space(l);
	else if (l->sign == 0)
	{
		if (l->nb_space <= l->nb_zero)
		{
			display_inferior(l);
			return(0);
		}
		else if (l->nb_space > l->nb_zero)
		{
			display_superior(l);
			return(0);
		}
		if (l->negative == 1)
			ft_putchar_fd('-', 1, l);
		ft_putstr_fd(l->stock, 1, l);
	}
	return(0);
}

void	display_precision_with_dash_letter(t_list *l)
{
	ft_putstr_letter(l->stock, l);
	if (l->sign == 1 && l->check_dash == 1)
	{
		if (l->nb_space < (int)ft_strlen(l->stock))
			return;
		else
		{
			l->nb_space = l->nb_space - ft_strlen(l->stock);
			while (l->nb_space > 0)
			{
				ft_putchar(' ', l);
				l->nb_space--;
			}
		}
	}
	else if (l->nb_zero >= (int)ft_strlen(l->stock))
	{
		if (l->nb_space > (int)ft_strlen(l->stock))
			l->nb_space = l->nb_space - ft_strlen(l->stock);
		else
				return;
	}
	else if (l->check_zero == 1 && l->check_dash == 1)
	{
		while (l->nb_space > 0)
			{
				ft_putchar(' ', l);
				l->nb_space--;
			}
	}
	else if ((l->nb_space <= l->nb_zero) && (l->nb_space < (int)ft_strlen(l->stock)))
		return;
	else
		l->nb_space = l->nb_space - l->nb_zero;
	while (l->nb_space > 0)
	{
		ft_putchar(' ', l);
		l->nb_space--;
	}
}

void	display_precision_letter(t_list *l)
{
	if (l->nb_space > 0)
	{
		while (l->nb_space > 0)
		{
			ft_putchar(' ', l);
			l->nb_space--;
		}
	}	
		ft_putstr_letter(l->stock, l);
}


void	display_only_space_letter(t_list *l)
{
	while (l->nb_space > 0)
	{
		ft_putchar(' ', l);
		l->nb_space--;
	}
}

void	display_space_letter(t_list *l)
{
	l->nb_space -= ft_strlen(l->stock);
	while (l->nb_space > 0)
	{
		ft_putchar(' ', l);
		l->nb_space--;
	}
	ft_putstr_fd(l->stock, 1, l);
}

void	display_space_with_dash_letter(t_list *l)
{
	ft_putstr_letter2(l->stock, l);
	l->nb_space = l->nb_space - ft_strlen(l->stock);
	while (l->nb_space > 0)
	{
		ft_putchar(' ', l);
		l->nb_space--;
	}
}

void display_zero2(t_list *l)
{
	if (l->negative == 1)
	{
		ft_putchar('-', l);
		l->nb_zero--;
	}	
	l->nb_zero = l->nb_zero - ft_strlen(l->stock) + 1;
	while (l->nb_zero > 0)
	{
		ft_putchar('0', l);
		l->nb_zero--;
	}
	ft_putstr_fd(l->stock, 1, l);
}

void display_zero(t_list *l)
{
	l->nb_space = l->nb_space - ft_strlen(l->stock);
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


char  *manage_c(int d, t_list *l)
{
	char *dest;
	char ouss[2];
	int i;

	i = 0;
	ouss[0] = d;
	ouss[1] = '\0';
	if (ouss[0] == '\0')
	{
		if (!(dest = malloc(sizeof(char) * 2)))
		return (0);
		while (i < 2)
		{
			dest[i] = ouss[i];
			i++;
		}
		l->count_print++;
		return (dest);
	}
	return (ft_strdup(ouss));
}  

char  *manage_modulo(char d)
{
	char *dest;
	char src[2];
	int i;

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

char *manage_type(const char *str, t_list *l, va_list v)
{
	if (str[l->i] == 's')
		l->stock = ft_strdup(va_arg(v, char *));	
	else if (str[l->i] == 'd' || str[l->i] == 'i')
	{	
		if (str)
				l->stock = ft_itoa(va_arg(v, int), l);
	}
	else if (str[l->i] == 'c')
		l->stock = manage_c(va_arg(v, int), l);	
	else if (str[l->i] == 'i')
		l->stock = ft_itoa(va_arg(v, int), l);
	else if (str[l->i] == 'u')
		l->stock = ft_itoa_u(va_arg(v, unsigned int), l);
	else if (str[l->i] == 'p')
		put_p(va_arg(v, void*), l);
	else if (str[l->i] == 'x')
		ft_putnbr_base(va_arg(v, unsigned int), "0123456789abcdef", l);	
	else if (str[l->i] == 'X')
		ft_putnbr_base(va_arg(v, unsigned int), "0123456789ABCDEF", l);
	else if (str[l->i] == '%')
		l->stock = manage_modulo('%');	
	return (l->stock);
}


int how_long(int nb_space)
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

void    manage_space(t_list *l, const char *str)
{
	if (str[l->i] == '0') 
	{
		l->check_space = 1;
		l->i++;
		if (str[l->i] > '0' && str[l->i] <= '9')
		{
			l->nb_space = ft_atoi(&str[l->i]);
			l->ret = how_long(l->nb_space);
			l->i = l->i + l->ret;
			l->i= l->i - 1;
		}
		return ;
	}
	else if (str[l->i] > '0' && str[l->i] <= '9')
	{
		l->nb_space = ft_atoi(&str[l->i]);
	}	
	l->ret = how_long(l->nb_space);
	l->i = l->i + l->ret;
}

void    manage_star_space(t_list *l, va_list v)
{
	l->nb_space = va_arg(v, int);
	if (l->nb_space == 0) 
	{
		l->check_space = 1;
	}
	else if (l->nb_space < 0)
	{
		l->check_dash = 1;
		l->nb_space = -l->nb_space;
	}
	l->i++;
}

void    manage_zero(t_list *l, const char *str)
{
	if (str[l->i] == '0') 
	{
		l->check_zero = 1;
		l->i++;
		return ;
	}
	else if (str[l->i] > '0' && str[l->i] <= '9')
	{
		l->nb_zero = ft_atoi(&str[l->i]);
	}	
	l->ret = how_long(l->nb_zero);
	l->i = l->i + l->ret;
}

void    manage_star_zero(t_list *l, va_list v)
{
	l->nb_zero = va_arg(v, int);
	if (l->nb_zero == 0) 
		l->check_zero = 1;
	else if (l->nb_zero < 0)
	{
		l->sign = 1;
		l->nb_zero = -l->nb_zero;
	}
	l->i++;
}


int	which_letter(const char *str, int i)
{
	if (str[i] && (str[i] == 'c' || str[i] == 's' || str[i] == 'p' || str[i] == 'd' || \
		str[i] == 'i' || str[i] == 'u' || str[i] == 'x' || str[i] == 'X' | str[i] == '%'))
		return (1);
	return (0);
}

void what_type(const char *str, int i, va_list v, t_list *l)
{
	if (str[i] == 's')
		ft_putstr_null(va_arg(v, char *), 1, l);	
	else if (str[i] == 'd')
		ft_putnbr_fd(va_arg(v, int), 1, l);
	else if (str[i] == 'c')
		ft_putchar_fd(va_arg(v, int), 1, l);
	else if (str[i] == 'i')
		ft_putnbr_fd(va_arg(v, int), 1, l);
	else if (str[i] == 'u')
		put_u(va_arg(v, unsigned int), l);
	else if (str[i] == 'p')
	{
		put_p(va_arg(v, void*), l);
		ft_putstr_fd(l->stock, 1, l);
	}	
	else if (str[i] == 'x')
	{
		ft_putnbr_base(va_arg(v, unsigned int), "0123456789abcdef", l);
		ft_putstr_fd(l->stock, 1, l);
	}	
	else if (str[i] == 'X')
	{
		ft_putnbr_base(va_arg(v, unsigned int), "0123456789ABCDEF", l);	
		ft_putstr_fd(l->stock, 1, l);
	}
	else if (str[i] == '%')
	{
		l->count_print++;
		write(1, "%", 1);
	}
		
			
}

void    search_flag(const char *str, va_list v, t_list *l)
{
	
	l->i++;
	if (which_letter(str, l->i) == 1)
	{
		// printf("carac actu = [%c]\n", str[l->i]);
		// printf("LAAAAAA\n");
		what_type(str, l->i, v, l);
		return ;
	}
	if (str[l->i] == '-')
	{
		// printf("CHECK DASH ||||||||| \n");
		l->check_dash = 1;
		l->i++;
	}
	while (str[l->i] && str[l->i] != '.' && which_letter(str, l->i) != 1)
	{
		if (str[l->i] >= '0' && str[l->i] <= '9')
		{
			// printf("FIRST STEP\n");
			manage_space(l, str);
		}
		else if (str[l->i] == '*')
		{
			manage_star_space(l, v);
		}
		else
			l->i++;
	}
	if (str[l->i] == '.' && l->i++)
		l->check_point = 1;

	while (str[l->i] && which_letter(str, l->i) != 1)
	{
		if (str[l->i] >= '0' && str[l->i] <= '9')
		{
			manage_zero(l, str);
		}
		else if (str[l->i] == '*')
		{
			manage_star_zero(l, v);
		}
		else
			l->i++;
	}

	// // printf("quel index = %d\n", l->i);

	// printf("VERIF CHECK POINT= %d\n", l->check_point);
	// printf("VERIF CHECK DASH = %d\n", l->check_dash);
	// printf("VERIF CHECK SPACE = %d\n", l->check_space);
	// printf("VERIF CHECK ZERO = %d\n", l->check_zero);
	// printf("NOMBRE SPACE = %d\n", l->nb_space);
	// printf("NOMBRE ZERO = %d\n", l->nb_zero);
	// // printf("quel carac = |%c|\n", str[l->i]);
	if (which_letter(str, l->i) == 1)
		l->stock = manage_type(str, l, v);
	// printf("stock = |%s|\n", l->stock);
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
						// printf("JJJJJJJJJJJJJJ\n");
						if (l->negative == 1)
							ft_putchar('-', l);
						ft_putstr_fd(l->stock, 1, l);
					}
					else if (l->check_zero == 0 && l->nb_space != 0 && l->nb_zero == 0)
					{
						// printf("DDDDDDDDDDDD\n");
						display_space_with_dash(l);
					}
					else if (l->check_zero == 0 && l->nb_space == 0 && l->nb_zero == 0)
					{
						// printf("JJJJJJJJJJJJJJ\n");
						if (l->negative == 1)
							ft_putchar('-', l);
						ft_putstr_fd(l->stock, 1, l);
					}
				}
				else if (l->check_space == 0)
				{
					if (l->check_zero == 0 && l->nb_space != 0 && l->nb_zero == 0)
					{
						// printf("BBBBBBBBBBBB\n");
						display_space_with_dash(l);
					}
					else if (l->check_zero == 0 && l->nb_space == 0 && l->nb_zero == 0)
					{
						// printf("BBBBBBBBBBBB\n");
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
					{
						// printf("CCCCCCCCCCCCC\n");
						display_zero(l);
					}
					else if (l->check_zero == 0 && l->nb_space == 0 && l->nb_zero == 0)
					{
						// printf("JJJJJJJJJJJJJJ\n");
						if (l->negative == 1)
							ft_putchar('-', l);
						ft_putstr_fd(l->stock, 1, l);
					}
				}
				else if (l->check_space == 0)
				{
					// printf("CCCCCCCCCCCCC\n");
					display_space(l);
				}
			}
		}
		else if ( l->check_point == 1)
		{
			if (l->check_dash == 1)
			{
				// printf("JJJJJJJJJJJJJJ\n");
				if (l->check_space == 0)
				{
					// printf("JJJJJJJJJJJJJJ\n");
					if (l->check_zero == 0)
					{
						// printf("JJJJJJJJJJJJJJ\n");
						if (l->nb_space != 0 && l->nb_zero == 0)
						{
							// printf("JJJJJJJJJJJJJJ\n");
							display_space_with_dash(l);
						}
						else if (l->nb_space != 0 && l->nb_zero != 0)
						{
							// printf("JJJJJJJJJJJJJJ\n");
							display_precision_with_dash(l);
						}
						else if (l->nb_space == 0 && l->nb_zero == 0)
						{
							// printf("JJJJJJJJJJJJJJ\n");
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
							{
								display_precision(l);
							}
							
						}
					}
					else if (l->check_zero == 1)
					{
						if (l->nb_space != 0 && l->nb_zero == 0)
						{
							// printf("HHHHHHHHHHHH\n");
							display_space_with_dash(l);
						}
						else if (l->nb_space == 0 && l->nb_zero == 0)
						{
							// printf("IIIIIIIIIIIIIII\n");
							if (l->negative == 1)
								ft_putchar('-', l);
							ft_putstr_fd(l->stock, 1, l);
						}
					}
				}
				else if (l->check_space == 1)
				{
					// printf("iiiciiii\n");
					if (l->check_zero == 0 && l->nb_space == 0 && l->nb_zero == 1)
					{
						// printf("JJJJJJJJJJJJJJ\n");
						if (l->negative == 1)
							ft_putchar('-', l);
						ft_putstr_fd(l->stock, 1, l);
					}
					else if (l->check_zero == 1 && l->nb_space == 0 && l->nb_zero == 0)
					{
						// printf("JJJJJJJJJJJJJJ\n");
						if (l->negative == 1)
							ft_putchar('-', l);
						ft_putstr_fd(l->stock, 1, l);
					}
					else if (l->check_zero == 0 && l->nb_space != 0)
					{
						// printf("JsJJJJJJJJJJJJJ\n");
						display_precision_with_dash(l);
					}
					else if (l->check_zero == 1 && l->nb_space != 0)
					{
						// printf("JJJJJJJJJJJJJJ\n");
						display_space_with_dash(l);
					}
					else if (l->check_zero == 0 && l->nb_space == 0)
					{
						if (l->sign == 1)
						{
							if (l->negative == 1)
								ft_putchar('-', l);
							ft_putstr_fd(l->stock, 1, l);
						}
						else
						{
							display_precision(l);
						}
						
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
						{
							// printf("EEEEEEE/÷s÷EEEEEE\n");
							display_precision(l);
						}
						else if (l->nb_space == 0 && l->nb_zero != 0)
						{
							// printf("EEEEEEEEEEsEEE\n");
							if (l->sign == 1)
							{
								// printf("EEEEEEEEEEsEEE\n");
								if (l->negative == 1)
									ft_putchar_fd('-', 1, l);
								ft_putstr_fd(l->stock, 1, l);
							}
							else
							{
								// printf("EEEEEEsEEEEsEEE\n");
								display_precision(l);
							}
							
						}
						else if (l->nb_space != 0 && l->nb_zero == 0)
						{
							// printf("EEEEEEsEEEEsEEE\n");
							display_precision(l);
						}

						else if (l->nb_space == 0 && l->nb_zero == 0)
						{
							// printf("EEEEEEEEEEEEE\n");
							if (l->negative == 1)
									ft_putchar_fd('-', 1, l);
							ft_putstr_fd(l->stock, 1, l);
						}
					}
					else if (l->check_zero == 1)
					{
						if (l->nb_space != 0 && l->nb_zero == 0)
						{
							// printf("GGGGGGGGGGGGG\n");
							display_space(l);
						}
						else if (l->nb_space == 0 && l->nb_zero == 0)
						{
							// printf("JJJJJJJJJJJJJJ\n");
							if (l->negative == 1)
									ft_putchar_fd('-', 1, l);
							ft_putstr_fd(l->stock, 1, l);
						}
					}
				}
				else if (l->check_space == 1)
				{
					// printf("FFFFFFFFFsFFFFFF\n");
					if (l->check_zero == 0 && l->nb_zero != 0)
					{
						// printf("FFFFFFFFFsFFFFFF\n");
						if (l->sign == 0)
						{
							// printf("OUIIIIIII\n");
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
							// printf("FFFFFFFFFsFFFFFF\n");
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
						{
							// printf("FFFFF/FFFFsFFFFFF\n");
							display_zero2(l);
						}
					}
					else if (l->check_zero == 0 && l->nb_zero == 0)
					{
						// printf("FFFFF/FFFFsFFFFFF\n");
						display_space(l);
					}
					else if (l->check_zero == 1)
					{
						display_precision(l);
					}
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
				{
					// printf("JJJJJJJJJJJJJJ\n");
					display_space_with_dash_letter(l);
				}
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
						{
							// printf("JJJJJJJsJJJJJJJ\n");
							display_only_space_letter(l);
						}
						else if (l->nb_zero != 0)
						{
							// printf("NOMBRE ZERO = %d\n", l->nb_zero);
							// printf("JJJJJJJJJJJJJJ\n");
							display_precision_with_dash_letter(l);
						}
					}
					else if (l->check_zero == 1 && l->nb_space != 0 && l->nb_zero == 0)
					{
						// printf("NOMBRE ZERO = %d\n", l->nb_zero);
						// printf("JJJJJJJJJJJJJJ\n");
						display_precision_with_dash_letter(l);
					}
					else if (l->nb_space == 0 && l->sign == 1 && l->nb_zero != 0)
						ft_putstr_fd(l->stock, 1, l);
					else if (l->nb_space == 0 && l->sign == 0 && l->nb_zero != 0)
						display_precision_letter(l);
				}
				else if (l->check_space == 1 && l->nb_zero != 0)
					{
						// printf("JJJJJJJJJJJJJJ\n");
						display_precision_with_dash_letter(l);
					}
			}
			else if (l->check_dash == 0)
			{
				if (l->check_space == 0)
				{
					if (l->check_zero == 0)
					{
						if (l->nb_space != 0 && l->nb_zero != 0)
						{
							// printf("JJJJJJJJJJJJJJ\n");
							if (l->sign == 1)
								l->nb_space -= ft_strlen(l->stock);
							else if (l->nb_zero < (int)ft_strlen(l->stock))
								l->nb_space -= l->nb_zero;
							else
								l->nb_space -= ft_strlen(l->stock);
							display_precision_letter(l); //CHECK
						}
						else if (l->nb_space == 0 && l->nb_zero != 0)
						{
							// printf("NOMBRE ZERO = %d\n", l->nb_zero);
							// printf("JJJJJJJJJJJJJJ\n");
							display_precision_letter(l);
						}
						else if (l->nb_space != 0 && l->nb_zero == 0)
						{
							l->nb_zero -= ft_strlen(l->stock);
							if (l->nb_zero >= 0)
								l->nb_space = l->nb_space - l->nb_zero;
							// printf("NOMBRE ZERO = %d\n", l->nb_zero);
							// printf("JJJJJJJJJJJJJJ\n");
							display_precision_letter(l);
						}
					}
					else if (l->check_zero == 1)
					{
						if (l->nb_space != 0 && l->nb_zero == 0)
						{
							// printf("NOMBRE ZERO = %d\n", l->nb_zero);
							// printf("JJJJJJJJJJJJJJ\n");
							display_precision_with_dash_letter(l);
						}
					}
				}
				else if (l->check_space == 1 && l->check_zero == 0 && l->nb_space == 0 && l->nb_zero != 0)
				{
					// printf("NOMBRE ZERO = %d\n", l->nb_zero);
					// printf("JJJJJJJJJJJJJJ\n");
					display_precision_letter(l);
				}
			}
		}
	}
	else if (str[l->i] == 'c')
	{
		if (l->check_point == 1 || l->check_point == 0)
		{
			display_precision_char(l);
		}
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
	
t_list *create_list(void)
{
	t_list *l;

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
	va_list v;
	t_list *l;
	int ret;

	va_start (v, str);
	if ((l = create_list()) == 0)
		return (0);	
	while (str[l->i] != '\0')
	{
		// printf("qui es tu = %c\n", str[l->i]);
		if (str[l->i] == '%')
		{ 
			// printf("j'envoi quoi = [%s]\n", &str[l->i + 1]);
			// printf("quel i = [%d]\n", l->i);
			search_flag(str, v, l);
			reset_list(l);
			//s arrete sur la lettre 9d, s, c, x, X ...)
			// printf("what return = %d\n", ret);
			// printf("str[i] = %c\n", str[i]);
		}
		else
		{
			write(1, &str[l->i], 1);
			l->count_print++;
		}
		l->i++;
	}
	ret = l->count_print;
	// printf("return = %d\n", l->count_print);
	if (l->stock)
		free(l->stock);
	free(l);
	return (ret);
}