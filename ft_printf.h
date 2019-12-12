/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:42:45 by nrochard          #+#    #+#             */
/*   Updated: 2019/12/12 02:19:07 by nrochard         ###   ########.fr       */
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
	int			check;
	int			sign;
	int			nb_zero;
	int			ret;
	int			nb_space;
	char		*stock;
    int         count_print;
}				t_list;


int     ft_printf(const char *str, ...);

void	ft_putchar(char c, t_list *l);
void	ft_putnbr_u(unsigned n, t_list *l);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int     ft_atoi(const char *str);
int     ft_isdigit(int c);
size_t  ft_strlen(const char *str);
char		*ft_itoa(int n, t_list *l);
char		*ft_itoa_u(unsigned int n, t_list *l);
int     main();

int					ft_atoi(const char *str);
void				ft_putchar_fd(char c, int fd, t_list *l);
void				ft_putnbr_fd(int n, int fd, t_list *l);
void	            ft_putnbr_base(unsigned int nbr, char *base, t_list *l);
void	            ft_putstr_fd(char *s, int fd, t_list *l);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *src);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *str);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);



#endif