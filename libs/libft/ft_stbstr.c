#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *ret;
    size_t  sizeS;
    int     i;

    i = 0;
    if (!s)
        return(NULL);
    sizeS = ft_strlen(s);
    if (start > sizeS)
        return(ft_strdub(""));
    if (len > sizeS - start)
        len = sizeS - start;
    ret = (char *)malloc(sizeof(char) * (len + 1));
    if (!ret)
        return (NULL);
    while (s[i + start] && i < len)
    {
        ret[i] = (char)s[i + start];
        i++;
    }
    ret[i] = '\0';
    return (ret);
}