#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
char *ft_strdup(char *s);
size_t ft_strlen(char *str);
char *ft_strjoin(char *s1, char *s2);
char *get_next_line(int fd);
#endif