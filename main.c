#include <stdarg.h>
#include <stdio.h>
// int sum (int count,...)
// {  
    
//     va_list args;
//     va_start(args,count);

//     int result  = 0;
//     int i = 0;
//     while (i < count)
//     {
//         int tmp = va_arg(args,int);
//         result += tmp;
//         i++;
//     }
//     return (result);
// }

int ft_printf(char *str, ...)
{
    va_list args;
    va_start(args, str);

    int i = 0;
    int count = 0;
    while (str[i])
    {
        if (str[i] == '%' && str[i + 1] == 's')
        {
            char *ss = va_arg(args, char *);
            count += printf("%s", ss);
            i += 2;
        }
        else if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
        {
            int ss = va_arg(args, int);
            count += printf("%d", ss);
            i += 2;
        }
        else if (str[i] == '%' && str[i + 1] == '%')
        {
            char m = '%';
            count += printf("%c", m);
            i += 2;
        }
        else if (str[i] == '%' && str[i + 1] == 'c')
        {
            int c = va_arg(args, int);
            count += printf("%c", c);
            i += 2;
        }
        else if (str[i] == '%' && str[i + 1] == 'u')
        {
            unsigned int n = va_arg(args, unsigned int);
            count += printf("%u", n);
            i += 2;
        }
        else if (str[i] == '%' && str[i + 1] == 'x')
        {
            unsigned int n = va_arg(args, unsigned int);
            count += printf("%x", n);
            i += 2;
        }
        else if (str[i] == '%' && str[i + 1] == 'X')
        {
            unsigned int n = va_arg(args, unsigned int);
            count += printf("%X", n);
            i += 2;
        }
        else if (str[i] == '%' && str[i + 1] == 'p')
        {
            void *p = va_arg(args, void *);
            count += printf("%p", p);
            i += 2;
        }
        else
        {
            count += printf("%c", str[i]);
            i++;
        }
    }
    va_end(args);
    return (count);
}

int main()
{

    ft_printf("Hello %s %s %d%% %c %u\n","Rayan","Ss",16, 'f', 42);
}
