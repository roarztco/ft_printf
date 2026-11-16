/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghomari <rghomari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 21:18:46 by rghomari          #+#    #+#             */
/*   Updated: 2026/11/16 22:30:26 by rghomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddress(uintptr_t ptr)
{
	int		count;
	int		result;
	char	*digits;

	count = 0;
	digits = "0123456789abcdef";
	if (ptr >= 16)
	{
		result = ft_putaddress(ptr / 16);
		if (result < 0)
			return (-1);
		count += result;
	}
	if (ft_putchar(digits[ptr % 16]) < 0)
		return (-1);
	return (count + 1);
}

int	ft_putpointer(void *p)
{
	int	count;
	int	result;

	if (!p)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	if (count < 0)
		return (-1);
	result = ft_putaddress((uintptr_t)p);
	if (result < 0)
		return (-1);
	return (count + result);
}
