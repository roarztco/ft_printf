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

int ft_printf(char *str,...)
{
    va_list args;
    va_start(args,str);

    int i = 0;
    while (str[i])
    {
        if (str[i] == '%' && str[i + 1] == 's')
        {
            char *ss = va_arg(args,char *);
            printf("%s",ss);
            i += 2;
        }
        else if (str[i] == '%' && str[i + 1] == 'd')
        {
            int ss = va_arg(args,int);
            printf("%d",ss);
            i += 2;
        }
        else{

            printf("%c",str[i]);
            i++;
        }
    }
    va_end(args);
    return (i);
}

int main()
{

    char arr[17] = "0123456789abcdef";
    ft_printf("Hello %s %s %d\n","Rayan","Ss",16);
}
