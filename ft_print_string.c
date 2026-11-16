/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghomari <rghomari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 21:18:26 by rghomari          #+#    #+#             */
/*   Updated: 2026/11/16 21:18:28 by rghomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putstr(char *s)
{
    int count;

    count = 0;
    while(*s)
    {
        count += ft_putchar(*s);
        s++;
    }
    return count;
}