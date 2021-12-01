#include "get_next_line.h"
size_t ft_strlen(char *str)
{
    int i = 0;
    if (!str)
        return 0;
    while (str[i])
    {
        i++;
    }
    return i;
}


char *ft_strdup(char *s)
{
    int i = 0;
    char *dest;

    dest = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
    if (!dest)
        return(0);
    while (s[i])
    {
        dest[i] = s[i];
        i++;
    }
    dest[i] = '\0';
    return(dest);    
}

char *ft_strjoin(char *s1, char *s2)
{
   unsigned int i = 0;
   char *str;
   unsigned int len1 = ft_strlen(s1);
   unsigned int len2 = ft_strlen(s2);

   str = (char *)malloc((len1 +len2 + 1) * sizeof(char));
   while (i < len1)
   {
       str[i] = s1[i];
       i++;
   }
   i = 0;
   while (i < len2)
   {
       str[i + len1] = s2[i];
       i++;
   }
   str[len1 + len2] = '\0';
   free((char *)s1);
   return(str);
}
