/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghomari <rghomari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 19:38:25 by rghomari          #+#    #+#             */
/*   Updated: 2026/11/19 20:15:05 by rghomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conversion(char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(*args, unsigned int)));
	else if (c == 'x')
		return (ft_putnbr_unsigned16(va_arg(*args, unsigned int),
				"0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_unsigned16(va_arg(*args, unsigned int),
				"0123456789ABCDEF"));
	else if (c == 'p')
		return (ft_putpointer(va_arg(*args, void *)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		result;

	if (!str)
		return (-1);
	va_start(args, str);
	i = -1;
	count = 0;
	result = 0;
	while (result >= 0 && str[++i])
	{
		if (str[i] == '%')
			result = ft_conversion(str[++i], &args);
		else
			result = ft_putchar(str[i]);
		if (result >= 0)
			count += result;
	}
	va_end(args);
	if (result < 0)
		return (-1);
	return (count);
}
