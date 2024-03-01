#include "libft.h"

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    unsigned int    idx;
    unsigned int    len;
    char    *result;

    idx = 0;
    len = (unsigned int)ft_strlen(s);
    result = (char *)malloc(sizeof(char) * (len + 1));
    if (!result)
        return (0);
    while (idx < len)
    {
        result[idx] = f(idx, s[idx]);
        idx++;
    }
    result[idx] = 0;
    return (result);
}