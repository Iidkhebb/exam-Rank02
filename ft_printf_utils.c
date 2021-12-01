#include "ft_printf.h"

void ft_putstr(char *str,int *count)
{
    int i = 0;
    if (!str)
    {
        *count += write(1, "(null)", 6);
        return ;
    }
    while (str[i])
    {
        *count += write(1, &str[i], 1);
        i++;
    }
}

void ft_putnbr(int nbr, int *count)
{
    char *base = "0123456789";
    int i = 10;

    if (nbr < 0)
    {
        nbr *= -1;
        *count += write(1, "-", 1);
    }
    if (nbr >= i)
    {
        ft_putnbr(nbr / i, count);
        ft_putnbr(nbr % i, count);
    }
    else
        *count += write(1, nbr + base, 1);
}

void ft_puthexa(unsigned int nbr, int *count)
{
    char *base = "0123456789abcdef";
    unsigned int i = 16;

    if (nbr >= i)
    {
        ft_puthexa(nbr / i, count);
        ft_puthexa(nbr % i, count);
    }
    else
        *count += write(1, nbr + base, 1);
}