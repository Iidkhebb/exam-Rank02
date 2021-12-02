#include<unistd.h>

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
void ft_union(char *s1, char *s2)
{
	int i = 0;

	while(s1[i])
	{
		if (kayen(s1, i, s1[i]))
			write(1, &s1[i], 1);
		i++;
	}
	int len = i;
	i = 0;
	while(s2[i])
	{
		if (kayen(s2, i, s2[i]))
		{
			if (kayen(s1, len, s2[i]))
				write(1, &s2[i], 1);
		}
		i++;
	}
}
int main (int ac, char *av[])
{
	int i = 0;
	if (ac == 3)
	{
		ft_union(av[1], av[2]);
	}
	else
		write(1, "\n", 1);
}
