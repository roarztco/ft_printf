/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghomari <rghomari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 19:38:25 by rghomari          #+#    #+#             */
/*   Updated: 2026/11/20 18:25:46 by rghomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(*args, unsigned int)));
	if (c == 'x')
		return (ft_putnbr_unsigned16(va_arg(*args, unsigned int),
				"0123456789abcdef"));
	if (c == 'X')
		return (ft_putnbr_unsigned16(va_arg(*args, unsigned int),
				"0123456789ABCDEF"));
	if (c == 'p')
		return (ft_putpointer(va_arg(*args, void *)));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		result;

	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%' && str[1])
		{
			str++;
			result = ft_format(*str, &args);
		}
		else
			result = ft_putchar(*str);
		if (result == -1)
		{
			va_end(args);
			return (-1);
		}
		count += result;
		str++;
	}
	va_end(args);
	return (count);
}
