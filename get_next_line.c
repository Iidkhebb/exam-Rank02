#include "get_next_line.h"
int buffer_len(char *str_static)
{
    int i = 0;
    if (!str_static)
        return (-1);
    while (str_static[i] != '\0' && str_static[i] != '\n')
    {
        i++;
    }
    if (str_static[i] == '\0')
        return(-1);
    return(i);
}
char *line_cutter(char *str_static)
{
    char *new_str;
    int i = 0;
    int pos;
    if (!str_static)
        return(NULL);
    pos = buffer_len(str_static);
    if (pos == -1)
        return(ft_strdup(str_static));
    new_str = (char *)malloc(pos + 2 * sizeof(char));
    if (!new_str)
        return(NULL);
    while (str_static[i] != '\n')
    {
        new_str[i] = str_static[i];
        i++;
    }
    new_str[i] = '\n';
    new_str[i + 1] = '\0';
    return(new_str);
}
char *old_line_rm(char *str_static)
{
    int pos;
    int remaining;
    char *new_buff;
    if (!str_static)
        return(NULL);
    pos = buffer_len(str_static);
    remaining = (int)ft_strlen(str_static);
    if (pos == -1 || (remaining - pos) == 1)
        return(free(str_static), NULL);
    new_buff = ft_strdup(str_static + pos + 1);
    free((char *)str_static);
    return(new_buff);
}
char *get_next_line(int fd)
{
    static char *str_static;
    char *str_tmp;
    int rt;
    char *new_str;
    if(BUFFER_SIZE <= 0 || fd < 0)
        return NULL;
    str_tmp = (char *)malloc(BUFFER_SIZE + 1);
    if (!str_tmp)
        return NULL;
    while (buffer_len(str_static) == -1)
    {
        rt = read(fd, str_tmp, BUFFER_SIZE);
        if (rt <= 0)
            break;
        str_tmp[rt] = '\0';
        str_static = ft_strjoin(str_static, str_tmp);
    }
    free(str_tmp);
    new_str = line_cutter(str_static);
    str_static = old_line_rm(str_static);
    return(new_str);
}
/*
#include <fcntl.h>
#include <stdio.h>
int main()
{
    int fd;
    char *line;
    int i;
    i =0;
    fd = open("test.txt", O_RDWR | O_CREAT);
    //printf("the FD is : %d\n",fd);
    while(line)
    {
        line = get_next_line(fd);
        printf("%s",line);
    }
    return (0);
}*/