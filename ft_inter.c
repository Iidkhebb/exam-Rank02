#include <unistd.h>

int kayen(char *str, int pos, char c)
{
	int i = 0;
	while(i < pos)
	{
		if (str[i] == c)
			return(0);
		i++;
	}
	return(1);
}

int fun(char *str, char c)
{
	int i = 0;
	while(str[i])
	{
		if (str[i] == c)
			return(1);
		i++;
	}
	return(0);
}

int main(int ac, char *av[])
{
	int i = 0;
	if (ac == 3)
	{
		while(av[1][i])
		{
			if (fun(av[2], av[1][i]) && kayen(av[1], i, av[1][i]))
				write(1, &av[1][i], 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
}
