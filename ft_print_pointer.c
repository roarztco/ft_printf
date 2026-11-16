/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghomari <rghomari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 21:18:46 by rghomari          #+#    #+#             */
/*   Updated: 2026/11/16 21:33:45 by rghomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putaddress(uintptr_t ptr)
{
    int count;
    char *digits;

    count = 0;
    digits = "0123456789abcdef";
    if(ptr >= 16)
        count += ft_putaddress(ptr / 16);
    count += ft_putchar(digits[ptr % 16]);
    return count;
}

int ft_putpointer(void *p)
{
    int count;

    count = ft_putstr("0x");
    count += ft_putaddress((uintptr_t)p);
    return count;
}