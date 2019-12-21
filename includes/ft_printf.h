/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:42:45 by nrochard          #+#    #+#             */
/*   Updated: 2019/12/21 12:28:39 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct	s_list
{
	int		i;
	int		check_space;
	int		check_zero;
	int		check_point;
	int		check_dash;
	int		sign;
	int		nb_zero;
	int		ret;
	int		nb_space;
	char	*stock;
	int		negative;
	int		tmp;
	int		count_print;
}				t_list;

int				ft_printf(const char *str, ...);

void			search_flag(const char *str, va_list v, t_list *l);
void			search_flag1(const char *str, va_list v, t_list *l);
void			search_flag2(t_list *l);
void			search_flag3(t_list *l);
void			search_flag4(t_list *l);
void			search_flag5(t_list *l);
void			search_flag6(t_list *l);
void			search_flag7(t_list *l);
void			search_flag8(t_list *l);
void			search_flag9(t_list *l);
void			search_flag10(t_list *l);
void			search_flag11(t_list *l);
void			search_flag12(t_list *l);
void			search_flag13(t_list *l);
void			search_flag14(t_list *l);

void			search_string(t_list *l);
void			search_number(t_list *l);
void			search_char(t_list *l);
void			search_modulo(t_list *l);

int				how_long(int nb_space);
int				which_letter(const char *str, int i);

void			reset_list(t_list *l);
t_list			*create_list(void);

void			what_type(const char *str, int i, va_list v, t_list *l);
void			what_type2(const char *str, int i, va_list v, t_list *l);
int				which_letter(const char *str, int i);
char			*manage_type(const char *str, t_list *l, va_list v);
int				ft_strncmp(const char *s1, const char *s2, int n);

void			put_p(void *s, t_list *l);
void			put_u(unsigned int nb, t_list *l);
void			put_negative(t_list *l);

char			*manage_c(int d, t_list *l);
char			*manage_modulo(char d);
char			*manage_nb(int count, long nb2);
char			*ft_manage_zero(t_list *l);

void			manage_star_zero(t_list *l, va_list v);
void			manage_zero(t_list *l, const char *str);
void			manage_star_space(t_list *l, va_list v);
void			manage_space(t_list *l, const char *str);

void			display_space(t_list *l);
void			display_space_with_dash(t_list *l);
void			display_only_space(t_list *l);
void			display_zero2(t_list *l);
void			display_zero(t_list *l);

void			display_only_space_letter(t_list *l);
void			display_precision_letter(t_list *l);
void			display_space_with_dash_letter(t_list *l);
void			display_space_letter(t_list *l);

void			display_inferior(t_list *l);
void			display_superior(t_list *l);
int				display_precision(t_list *l);
void			display_precision_with_dash_letter(t_list *l);
void			display_precision_with_dash_letter2(t_list *l);
void			display_precision_char(t_list *l);
int				display_precision_with_dash(t_list *l);
void			display_precision_modulo(t_list *l);

void			ft_putstr_letter(char *s, t_list *l);
void			ft_putchar(char c, t_list *l);
void			ft_putnbr_u(unsigned n, t_list *l);
void			ft_putstr_letter2(char *s, t_list *l);
void			ft_putstr_null(char *s, int fd, t_list *l);
void			ft_putnbr_p(uintmax_t nbr, char *base, t_list *l);

char			*ft_itoa_u(unsigned int n, t_list *l);

int				ft_atoi(const char *str);
char			*ft_itoa(int n, t_list *l);
int				ft_strlen(const char *str);
void			ft_putchar_fd(char c, int fd, t_list *l);
void			ft_putnbr_fd(int n, int fd, t_list *l);
void			ft_putnbr_base(unsigned int nbr, char *base, t_list *l);
void			ft_putstr_fd(char *s, int fd, t_list *l);
char			*ft_strdup(const char *src);
void	        reverse_stock(t_list *l);

#endif
