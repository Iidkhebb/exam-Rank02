#include "get_next_line.h"
int ft_strlen(char *str)
{
	int i = 0;
	if (!str)
		return(0);
	while(str[i])
	{
		i++;
	}
	return(i);
}

char *ft_strdup(char *str)
{
	int i = 0;
	char *dest;
	dest = (char *)malloc(ft_strlen(str) + 1 * sizeof(char));
	if (!dest)
		return(NULL);
	while(str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return(dest);
}

char *ft_strjoin(char *s1, char *s2)
{
	unsigned int i= 0;
	unsigned int len1 = ft_strlen(s1);
	unsigned int len2 = ft_strlen(s2);
	char *dest;
	dest = (char *)malloc(len1 + len2 + 1 *sizeof(char) ); 
	if (!dest)
		return(NULL);
	while(i < len1)
	{
		dest[i] = s1[i];
		i++;
	}
	i = 0;
	while(i < len2)
	{
		dest[len1 + i] = s2[i];
		i++;
	}
	dest[i+ len1] = '\0';
	free((char *)s1);
	return(dest);
}
//func
int buffer_len(char *str)
{
	int i = 0;
	if (!str)
		return(-1);
	while(str[i] != '\0' && str[i] != '\n')
	{
		i++;
	}
	if (str[i] == '\0')
		return(-1);
	return(i);
}
char *line_cutter(char *str_static)
{
	int pos = buffer_len(str_static);
	char *new;
	int i = 0;
	if (!str_static)
		return(NULL);
	if (pos == -1)
		return(ft_strdup(str_static));
	new = (char *)malloc(pos + 2 *sizeof(char));
	if (!new)
		return(NULL);
	while(str_static[i] != '\n')
	{
		new[i] = str_static[i];
		i++;
	}
	new[i] = '\n';
	new[i+1] = '\0';
	return(new);
}
char *old_line_rm(char *str_static)
{
	int pos = buffer_len(str_static);
	int remaining = ft_strlen(str_static);
	char *new_buff;
	if(!str_static)
		return(NULL);
	if (pos == -1 || (remaining - pos) == 1)
		return(free(str_static), NULL);
	new_buff = ft_strdup(str_static + pos + 1);
	free((char *)str_static);
	return(new_buff);
}
char *get_next_line(int fd)
{
	int rt;
	char *new_str;
	char *tmp_str;
	static char *str_static;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	tmp_str = (char *)malloc(BUFFER_SIZE + 1);
	if (!tmp_str)
		return(NULL);
	while(buffer_len(str_static) == -1)
	{
		rt = read(fd, tmp_str, BUFFER_SIZE);
		if (rt <= 0)
			break;
		tmp_str[rt] = '\0';
		str_static = ft_strjoin(str_static, tmp_str);
	}
	free((char *)tmp_str);
	new_str = line_cutter(str_static);
	str_static = old_line_rm(str_static);
	return(new_str);
}/*
#include <stdio.h>
int main ()
{
	char *line;
	int fd;
	fd = open("test.txt", O_RDWR);
	while(line)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
}*/
