/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexadecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniah <daniah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 04:11:45 by daniah            #+#    #+#             */
/*   Updated: 2024/11/10 06:29:23 by daniah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_put_hexadecimal(unsigned int num, int lower)
{
    int count;

    count = 0;
    if (num == 0)
    {
        count+= ft_putchar('0');
        return (count);
    }
    if (num >= 16)
    {
        count += ft_put_hexadecimal(num / 16, lower);
    }
    count += ft_hexadecimal_digit(num % 16, lower);
    return (count);
}


// int main()
// {
//     unsigned int x;
//     x = 245;
//     ft_put_hexadecimal(x,1);
//     printf("\n");
//     ft_put_hexadecimal(x,0);
//     return (0);
// }

