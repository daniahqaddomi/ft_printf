/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dqaddomi <dqaddomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:24:14 by dqaddomi          #+#    #+#             */
/*   Updated: 2024/11/05 18:18:43 by dqaddomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putchar(int c)
{
	return(write(1, &c, 1));
}

int ft_putstring(char *str) {
    int       i;

    i = 0;
    if(str == NULL)
    {
       write(1,"(null)",6);
       return (6);
    }
    while (str[i] != '\0')
    {
       ft_putchar(str[i]);
       i++;
    }
    return(i);
}


int ft_putnumber(int n) {
    int count = 0;
    if (n == -2147483648)
        return ft_putstring("-2147483648");
    if (n < 0) {
        count += ft_putchar('-');
        n = -n;
    }
    if (n > 9)
        count += ft_putnumber(n / 10);
    count += ft_putchar((n % 10) + '0');
    return count;
}

int ft_putunsigned_int(unsigned int n) {
    int count = 0;
    if (n > 9)
        count += ft_putunsigned_int(n / 10);
    count += ft_putchar((n % 10) + '0');
    return count;
}

int ft_puthexadecimal(unsigned int n, int uppercase) {
    int count = 0;
    char *base = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
    if (n >= 16)
        count += ft_puthexadecimal(n / 16, uppercase);
    count += ft_putchar(base[n % 16]);
    return count;
}

int ft_putpointer(size_t ptr) {
    int count = 0;
    count += ft_putstring("0x");
    if (ptr == 0)
        count += ft_putchar('0');
    else
        count += ft_puthexadecimal((unsigned long)ptr, 0);
    return count;
}

// Check function for format specifiers
int ft_printfcheck(char c, va_list *args) {
    if (c == 'c')
        return ft_putchar(va_arg(*args, int));
    else if (c == 's')
        return ft_putstring(va_arg(*args, char *));
    else if (c == 'p')
        return ft_putpointer(va_arg(*args, size_t));
    else if (c == 'd' || c == 'i')
        return ft_putnumber(va_arg(*args, int));
    else if (c == 'u')
        return ft_putunsigned_int(va_arg(*args, unsigned int));
    else if (c == 'x')
        return ft_puthexadecimal(va_arg(*args, unsigned int), 0);
    else if (c == 'X')
        return ft_puthexadecimal(va_arg(*args, unsigned int), 1);
    else if (c == '%')
        return ft_putchar('%');
    return 0;
}
