/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghomari <rghomari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 20:55:00 by rghomari          #+#    #+#             */
/*   Updated: 2026/11/16 22:18:51 by rghomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;
	int	result;

	count = 0;
	if (n >= 10)
	{
		result = ft_putnbr_unsigned(n / 10);
		if (result < 0)
			return (-1);
		count += result;
	}
	if (ft_putchar(n % 10 + '0') < 0)
		return (-1);
	return (count + 1);
}

int	ft_putnbr(int n)
{
	unsigned int	nb;
	int				count;
	int				result;

	nb = (unsigned int)n;
	count = 0;
	if (n < 0)
	{
		if (ft_putchar('-') < 0)
			return (-1);
		count++;
		nb = 0u - nb;
	}
	result = ft_putnbr_unsigned(nb);
	if (result < 0)
		return (-1);
	return (count + result);
}

int	ft_putnbr_unsigned16(unsigned int n, char *base)
{
	int	count;
	int	result;

	count = 0;
	if (n >= 16)
	{
		result = ft_putnbr_unsigned16(n / 16, base);
		if (result < 0)
			return (-1);
		count += result;
	}
	if (ft_putchar(base[n % 16]) < 0)
		return (-1);
	return (count + 1);
}
