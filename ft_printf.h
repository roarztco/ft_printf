/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghomari <rghomari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 19:40:39 by rghomari          #+#    #+#             */
/*   Updated: 2026/11/16 21:38:43 by rghomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>

int ft_putchar(char c);
int ft_putstr(char *s);
int ft_putnbr(int n);
int ft_putnbr_unsigned(unsigned int n);
int ft_putnbr_unsigned16(unsigned int n, char *base);
int ft_putaddress(uintptr_t ptr);
int ft_putpointer(void *p);
