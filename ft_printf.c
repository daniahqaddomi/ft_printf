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

static void ft_printfcheck(char c, va_list *args, int *i)
{
	 if (c == 's')
		  ft_putstring(va_arg(*args, char *));
	 else if (c == 'c')
		 ft_putchar(va_arg(*args, int));
	 else if (c == 'p')
		 ft_putpointer(va_arg(*args, size_t));
	 else if (c == 'd' || c == 'i') 
		 ft_putnumber(va_arg(*args, int));
	 else if (c == 'u')
		 ft_putunsigned_int(va_arg(*args, unsigned int));
	 else if (c == 'x')
		 ft_puthexadecimal(va_arg(*args, unsigned int));
	 else if (c == 'X')
		 ft_puthexadecimal(va_arg(*args, unsigned int));
	 else if (c == '%')
		 ft_putchar('%');
		 
	 else 
		 (*i)--;
}


int ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		char_count;

	i = 0;
	char_count = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			char_count += ft_printfcheck(string[i], args);
		}
		else
		{
			char_count += ft_putchar(string[i]);
		}
		i++;
	}
		va_end(args);
		return (char_count);
}



















