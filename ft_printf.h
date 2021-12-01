#ifndef FT_PRINTF_H
#define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

void ft_putstr(char *str,int *count);
void ft_putnbr(int nbr, int *count);
void ft_puthexa(unsigned int nbr, int *count);
#endif