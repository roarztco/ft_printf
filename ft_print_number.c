/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghomari <rghomari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 20:55:00 by rghomari          #+#    #+#             */
/*   Updated: 2026/11/21 11:57:38 by rghomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	nb;
	long	div;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		count++;
		nb = -nb;
	}
	div = 1;
	while (nb / div >= 10)
		div *= 10;
	while (div > 0)
	{
		if (ft_putchar(nb / div % 10 + '0') == -1)
			return (-1);
		count++;
		div /= 10;
	}
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	unsigned int	div;
	int				count;

	div = 1;
	count = 0;
	while (n / div >= 10)
		div *= 10;
	while (div > 0)
	{
		if (ft_putchar(n / div % 10 + '0') == -1)
			return (-1);
		count++;
		div /= 10;
	}
	return (count);
}

int	ft_putnbr_unsigned16(size_t n, const char *base)
{
	size_t			div;
	int				count;

	div = 1;
	count = 0;
	while (n / div >= 16)
		div *= 16;
	while (div > 0)
	{
		if (ft_putchar(base[n / div % 16]) == -1)
			return (-1);
		count++;
		div /= 16;
	}
	return (count);
}
