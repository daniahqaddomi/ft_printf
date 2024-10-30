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

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			ft_printcheck(string[i], &args, &length, &i);
			i++;
		}
		else
		{
			ft_putcharacter((char)string[i], &length);
			i++;
		}
	}
	va_end(args);
	return (length);
}


#include "ft_printf.h"

int	print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

void ft_putstr(char *str)
{
    if (str == NULL) 
        return; 
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
        return (6); 
    }
    int i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i); 
}

#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c) {
    return write(1, &c, 1);
}

int ft_putstr(char *str) {
    int len = 0;
    while (str[len]) {
        ft_putchar(str[len]);
        len++;
    }
    return len;
}

int ft_printf(const char *format, ...) {
    va_list args;
    int i = 0;
    int printed_chars = 0;

    va_start(args, format); 

    while (format[i]) {
        if (format[i] == '%' && format[i + 1] == 's') {
            char *str = va_arg(args, char *);
            printed_chars += ft_putstr(str);
            i += 2; 
        } else {
            ft_putchar(format[i]);
            printed_chars++;
            i++;
        }
    }

    va_end(args);
    return printed_chars;
}

int main() {
    ft_printf("Hello, %s!\n", "42");
    return 0;
}

