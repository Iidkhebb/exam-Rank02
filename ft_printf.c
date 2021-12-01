#include "ft_printf.h"
void conversions(const char *str, va_list data, int *count)
{
    if (*str == 's')
    {
        ft_putstr(va_arg(data, char *), count);
    }
    else if (*str == 'x')
    {
        ft_puthexa(va_arg(data, unsigned int), count);
    }
    else if (*str == 'd')
    {
        ft_putnbr(va_arg(data, int), count);
    }
}
int ft_printf(const char *str, ...)
{
    int i = 0;
    int count = 0;
    va_list data;
    va_start(data, str);

    while (str[i])
    {
        if (str[i] == '%')
        {
            if (str[i + 1] == '%')
                count += write(1, "%", 1);
            else
                conversions(&str[i + 1],data, &count);
            i++;    
        }
        else
        {
            count += write(1, &str[i], 1);
        }
        i++;
    }
    va_end(data);
    return(count);
}
int main()
{
    char *s = NULL;
    ft_printf("%s",s );
}