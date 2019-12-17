/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:42:45 by nrochard          #+#    #+#             */
/*   Updated: 2019/12/17 00:50:08 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct	s_list
{
	int			i;
	int			check_space;
    int			check_zero;
    int			check_point;
    int			check_dash;
	int			sign;
	int			nb_zero;
	int			ret;
	int			nb_space;
	char		*stock;
	int 		negative;
	int			tmp;
    int         count_print;
}				t_list;


int     ft_printf(const char *str, ...);

void	ft_putchar(char c, t_list *l);
void	ft_putnbr_u(unsigned n, t_list *l);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int     ft_atoi(const char *str);
int     ft_isdigit(int c);
int     ft_strlen(const char *str);
void	ft_putstr_letter2(char *s, t_list *l);
void	ft_putstr_null(char *s, int fd, t_list *l);
char		*ft_itoa(int n, t_list *l);
char		*ft_itoa_u(unsigned int n, t_list *l);
int     main();
void	ft_putstr_letter(char *s, t_list *l);
int					ft_atoi(const char *str);
void				ft_putchar_fd(char c, int fd, t_list *l);
void				ft_putnbr_fd(int n, int fd, t_list *l);
void	            ft_putnbr_base(unsigned int nbr, char *base, t_list *l);
void	            ft_putstr_fd(char *s, int fd, t_list *l);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *src);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);



#endif