/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghomari <rghomari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 19:38:25 by rghomari          #+#    #+#             */
/*   Updated: 2026/11/16 21:35:00 by rghomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(char *str, ...)
{
    int i;
    int count;
    
    va_list args;
    va_start(args, str);

    count = 0;
    i = 0;
    while(str[i])
    {
        if(str[i] == '%' && str[i + 1] == 'c')
        {
            count += ft_putchar(va_arg(args, int));
            i += 2;
        }
        else if(str[i] == '%' && str[i + 1] == '%')
        {
            count += ft_putchar('%');
            i += 2;
        }
        else if(str[i] == '%' && str[i + 1] == 's')
        {
            count += ft_putstr(va_arg(args, char *));
            i += 2;
        }
        else if(str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
        {
            count += ft_putnbr(va_arg(args, int));
            i += 2;
        }
        else if(str[i] == '%' && str[i + 1] == 'u')
        {
            count += ft_putnbr_unsigned(va_arg(args, unsigned int));
            i += 2;
        }
        else if(str[i] == '%' && str[i + 1] == 'x')
        {
            char *digits = "0123456789abcdef";
            count += ft_putnbr_unsigned16(va_arg(args, unsigned int), digits);
            i += 2;
        }
        else if(str[i] == '%' && str[i + 1] == 'X')
        {
            char *digits = "0123456789ABCDEF";
            count += ft_putnbr_unsigned16(va_arg(args, unsigned int), digits);
            i += 2;
        }
        else if(str[i] == '%' && str[i + 1] == 'p')
        {
            char *digits = "0123456789abcdef";
            count += ft_putpointer(va_arg(args, void *));
            i += 2;
        }
        else
        {
            count += ft_putchar(str[i]);
            i++;
        }
    }
    va_end(args);
    return count;
}
