/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghomari <rghomari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 20:55:00 by rghomari          #+#    #+#             */
/*   Updated: 2026/11/16 21:04:05 by rghomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putnbr(int n)
{
    long nb;
    int count;

    count = 0;
    nb = n;
    if(n < 0)
    {
        count += ft_putchar('-');
        nb = -nb;
    }
    if(nb >= 10)
        count += ft_putnbr(nb / 10);
    count += ft_putchar(nb % 10 + '0');
    return count;
}

int ft_putnbr_unsigned(unsigned int n)
{
    int count;

    count = 0;
    if(n >= 10)
        count += ft_putnbr_unsigned(n / 10);
    count += ft_putchar(n % 10 + '0');
    return count;
}

int ft_putnbr_unsigned16(unsigned int n, char *base)
{
    int count;

    count = 0;
    if(n >= 16)
        count += ft_putnbr_unsigned16(n / 16, base);
    count += ft_putchar(base[n % 16]);
    return count;
}