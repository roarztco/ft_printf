#include <stdarg.h>
#include <stdio.h>

// int ft_printf(char *str, ...)
// {
//     va_list args;
//     va_start(args, str);

//     int i = 0;
//     int count = 0;
//     while (str[i])
//     {
//         if (str[i] == '%' && str[i + 1] == 's')
//         {
//             char *ss = va_arg(args, char *);
//             count += printf("%s", ss);
//             i += 2;
//         }
//         else if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
//         {
//             int ss = va_arg(args, int);
//             count += printf("%d", ss);
//             i += 2;
//         }
//         else if (str[i] == '%' && str[i + 1] == '%')
//         {
//             char m = '%';
//             count += printf("%c", m);
//             i += 2;
//         }
//         else if (str[i] == '%' && str[i + 1] == 'c')
//         {
//             int c = va_arg(args, int);
//             count += printf("%c", c);
//             i += 2;
//         }
//         else if (str[i] == '%' && str[i + 1] == 'u')
//         {
//             unsigned int n = va_arg(args, unsigned int);
//             count += printf("%u", n);
//             i += 2;
//         }
//         else if (str[i] == '%' && str[i + 1] == 'x')
//         {
//             unsigned int n = va_arg(args, unsigned int);
//             count += printf("%x", n);
//             i += 2;
//         }
//         else if (str[i] == '%' && str[i + 1] == 'X')
//         {
//             unsigned int n = va_arg(args, unsigned int);
//             count += printf("%X", n);
//             i += 2;
//         }
//         else if (str[i] == '%' && str[i + 1] == 'p')
//         {
//             void *p = va_arg(args, void *);
//             count += printf("%p", p);
//             i += 2;
//         }
//         else
//         {
//             count += printf("%c", str[i]);
//             i++;
//         }
//     }
//     va_end(args);
//     return (count);
// }

#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
		str = "(null)";
	while (*str)
	{
		count += ft_putchar(*str);
		str++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_putnbr(nb / 10);
	count += ft_putchar(nb % 10 + '0');
	return (count);
}

int ft_putnbr_unsigned(unsigned int nb)
{
    int count;

    count = 0;
    if(nb >= 10)
        count += ft_putnbr_unsigned(nb / 10);
    count += ft_putchar(nb % 10 + '0');
    return count;
}

int ft_putnbr_base16(unsigned int nb, char *digits)
{
	int		count;

	count = 0;
	if (nb >= 16)
		count += ft_putnbr_base16(nb / 16);
    count += ft_putchar(digits[nb % 16]);
    return count;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == 's')
		{
			count += ft_putstr(va_arg(args, char *));
			i += 2;
		}
		else if (str[i] == '%' && (str[i + 1] == 'd'
				|| str[i + 1] == 'i'))
		{
			count += ft_putnbr(va_arg(args, int));
			i += 2;
		}
		else if (str[i] == '%' && str[i + 1] == '%')
		{
			count += ft_putchar('%');
			i += 2;
		}
		else if (str[i] == '%' && str[i + 1] == 'c')
		{
			count += ft_putchar(va_arg(args, int));
			i += 2;
		}
        else if(str[i] == '%' && str[i + 1] == 'u')
        {
            unsigned int nb = va_arg(args, unsigned int);
            count += ft_putnbr_unsigned(nb);
            i += 2;
        }
        else if(str[i] == '%' && str[i + 1] == 'x')
        {
            char *digits = "0123456789abcdef";
            unsigned int nb = va_arg(args, unsigned int);
            count += ft_putnbr_base16(nb, digits);
            i += 2;
        }
        else if(str[i] == '%' && str[i + 1] == 'X')
        {
            char *digits = "0123456789ABCDEF";
            unsigned int nb = va_arg(args, unsigned int);
            count += ft_putnbr_base16(nb, digits);
            i += 2;
        }
        else if(str[i] == '%' && str[i + 1] == 'p')
        {

        }
		else
		{
			count += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}





// int main()
// {

//     ft_printf("Hello %s %s %d%% %c %u\n","Rayan","Ss",16, 'f', 42);
// }
