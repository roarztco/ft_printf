/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghomari <rghomari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 21:18:26 by rghomari          #+#    #+#             */
/*   Updated: 2026/11/20 18:27:35 by rghomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *s)
{
	int	count;

	if (s == NULL)
		return (ft_putstr("(null)"));
	count = 0;
	while (*s)
	{
		if (ft_putchar(*s) == -1)
			return (-1);
		count++;
		s++;
	}
	return (count);
}
