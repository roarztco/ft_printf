/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghomari <rghomari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 21:18:46 by rghomari          #+#    #+#             */
/*   Updated: 2026/11/20 18:26:18 by rghomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(void *p)
{
	int	count;
	int	result;

	if (p == NULL)
		return (ft_putstr("(nil)"));
	count = 0;
	if (ft_putstr("0x") == -1)
		return (-1);
	count += 2;
	result = ft_putnbr_unsigned16((size_t)p, "0123456789abcdef");
	if (result == -1)
		return (-1);
	return (count + result);
}
