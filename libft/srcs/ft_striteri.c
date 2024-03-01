#include "libft.h"

void    ft_striteri(char *s, void (*f)(unsigned int, char *))
{
    size_t  idx;

    idx = 0;
    while (s[idx])
    {
        f(i, &s[idx]);
        idx++;
    }
}