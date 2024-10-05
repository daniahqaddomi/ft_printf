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

#include "ft_printf.h"

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

#include "ft_printf.h"

int	printf_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
#include "ft_printf.h"

int	print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
void ft_putstr(char *str)
{
    if (str == NULL) // Check for NULL
        return; // Or handle accordingly, e.g., write a default message.
    int i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

int ft_printstr(char *str)
{
    if (str == NULL)
    {
        ft_putstr("(null)");
        return (6); // Returning the length of "(null)"
    }
    int i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i); // Return the length of the string
}
