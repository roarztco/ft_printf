#include <stdarg.h>

int ft_sum(int count, ...)
{
    va_list args;
    va_start(args, count);

    int i = 0;
    int result = 1;
    while(i < count)
    {
        int tmp = va_arg(args, int);
        result *= tmp;
        i++;
    }
    va_end(args);
    return result;
}
int main()
{
    int s;
    s = ft_sum(2, 3, 2);
    #include <stdio.h>
    printf("%d\n", s);
}