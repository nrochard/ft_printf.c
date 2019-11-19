/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:42:45 by nrochard          #+#    #+#             */
/*   Updated: 2019/11/13 19:29:03 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
# include <string.h>
# include <stdlib.h>

struct t_list
{
    int i;
};


int     ft_printf(const char *str, ...);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_base(int nbr, char *base);
void	ft_putchar(char c);
void	ft_putnbr_u(unsigned n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int	ft_atoi(const char *str);
int	ft_isdigit(int c);
size_t	ft_strlen(const char *str);
int     main();

#endif