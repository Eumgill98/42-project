#include "libft.h"

char    *ft_strtrim(char const *s1, char const *set)
{
    size_t  start;
    size_t  end;
    char    *result;

    start = 0;
    end = ft_strlen(s1);
    while (s1[start] && ft_strrchr(set, s1[start]))
        start++;
    while (end >= 0 && ft_strchr(set, s1[end]))
        end--;
    if (start > end)
        return (ft_strdup(""));
    result = ft_substr(s1, start, end - start);
    return (result);
}
