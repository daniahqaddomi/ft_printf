/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniah <daniah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 06:24:42 by daniah            #+#    #+#             */
/*   Updated: 2024/11/10 06:29:34 by daniah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putpointer(void *ptr)
{
    int count;
    unsigned long address;

    count = 0;
    address = (unsigned long) ptr;

      if (ptr == NULL)
    {
        write(1,"0x0",3);
        return (3);
    }
    write (1,"0x",2);
    count += 2;
    count += ft_put_hexadecimal(address,1);
    return (count);
}
// int main()
// {
//     void *ptr = NULL;
//     ft_putpointer(ptr);
//     printf("\n");
//     int x = 1;
//     ft_putpointer(&x);
//     return 0;
// }