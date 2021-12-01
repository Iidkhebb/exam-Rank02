#include <unistd.h>
#include <stdio.h>
int kayen(char *str, char c)
{
    int i = 0;

    while (str[i])
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return(0);
}
int kayen2(char *str, int pos, char c)
{
    int i = 0;

    while (i < pos)
    {
        if (str[i] == c)
            return (0);
        i++;
    }
    return(1);
}
int		main(int ac, char *av[])
{
	int i = 0;
    int j = 0;
    if (ac == 3)
	{
        while (av[1][i])
        {
            if (kayen(av[2], av[1][i]) && kayen2(av[1], i , av[1][i]))
                write(1, &av[1][i], 1);
            i++;
        }
    }
	write(1, "\n", 1);
	return (0);
}

// padinto$
// nothig$
// df6ewg4$