/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dqaddomi <dqaddomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:24:14 by dqaddomi          #+#    #+#             */
/*   Updated: 2024/09/28 13:22:15 by dqaddomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <string.h>

static void ft_printfcheck(char c, va_list *args, int *len, int *i)
{
    if (c == 's')
        ft_putstring(va_arg(*args, char *), len);
    else if (c == 'c')
       ft_putchar(va_arg(*args, int), len);
    else if (c == 'p')
       ft_putpointer(va_arg(*args, size_t), len);
    else if (c == 'd' || c == 'i') 
       ft_putnumber(va_arg(*args, int), len);
    else if (c == 'u')
       ft_putunsigned_int(va_arg(*args, unsigned int), len);
    else if (c == 'x')
       ft_puthexadecimal(va_arg(*args, unsigned int), len);
    else if (c == 'X')
       ft_puthexadecimal(va_arg(*args, unsigned int), len);
    else if (c == '%')
       ft_putchar('%', len);
    else 
       (*i)--;      
}

int ft_printf(const char *string, ...)
{
    va_list   args;
    int       i;
    int       len;

    i = 0;
    len = 0;
    va_start(args, string);
    while (string != '\0')
    {
       if (string[i] == '%')
       {
              i++;
              ft_printfcheck(string[i], &args, &len, &i);
              i++;              
       }
       else
       {
              ft_putchar((char)string[i], &len);
              i++;
       }
    }
    va_end(args);
    return(len);      
}