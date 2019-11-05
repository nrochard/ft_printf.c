/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 14:38:14 by nrochard          #+#    #+#             */
/*   Updated: 2019/11/05 20:05:04 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf.h"

void put_s(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    write(1, s, i);
}

void find_modulo(const char *str, int i, va_list v)
{
	 if (str[i] == '%')
        {
            // if (str[i + 1] == 'c')
            // {
				
            // } 
            if (str[i + 1] == 's')
            {
                put_s(va_arg(v, char *));
            }
    //         if (str[i + 1] == 'p')
    //         {

    //         }
    //         if (str[i + 1] == 'd')
    //         {

    //         }
    //         if (str[i + 1] == 'i')
    //         {

    //         }
    //         if (str[i + 1] == 'u')
    //         {

    //         }
    //         if (str[i + 1] == 'x')
    //         {

    //         }
    //         if (str[i + 1] == 'X')
    //         {

    //         }
    }
}

int     ft_printf(const char *str, ...)
{
	va_list va;
	int i;
	int count;

	i = 0;
	count = 0;
	va_start (va, str);
	while(str[i] != '\0')
	{
		if (str[i] == '%')
			find_modulo(str, i, va);
		i++;
	}
	va_end(va);
    return (1);
	// return (< 0 s echec)
	// return(nb charac de read si ok sans '\0')
}

int main()
{
	char *s = "salut les copains";

	printf("%s\n", s);
	ft_printf("%s", s);
    return (0);
}