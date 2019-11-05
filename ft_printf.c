/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 14:38:14 by nrochard          #+#    #+#             */
/*   Updated: 2019/11/04 12:08:06 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
    va_list va;
    int i;

    i = 0;
    va_start (va, str);
    while (str[i] != '\0')
    {
        if (str[i] == "%")
        {
            if (str[i + 1] == 'c')
            {

            } 
            if (str[i + 1] == 'c')
            {

            }
            if (str[i + 1] == 'c')
            {

            }
            if (str[i + 1] == 'c')
            {

            }
            if (str[i + 1] == 'c')
            {

            }
            if (str[i + 1] == 'c')
            {

            }
            if (str[i + 1] == 'c')
            {

            }
            if (str[i + 1] == 'c')
            {

            }
    }
    va_end(va);

    // return (< 0 s echec)
    // return(nb charac de read si ok sans '\0')
}