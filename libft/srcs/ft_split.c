
#include "libft.h"

static size_t   ft_word_count(char const *s, char c)
{
    size_t  idx;
    size_t  count;

    idx = 0;
    count = 0;
    while (s[idx])
    {
        while (s[idx] && s[idx] == c)
            idx++;
        if (s[idx])
            count++;
        while (s[idx] && s[idx] != c)
            idx++;
    }
    return (count);
}

static size_t   ft_word_len(char const *s, char c)
{
    size_t  len;

    len = 0;
    while (s[len] && s[len] != c)
        len++;
    return (len);
}

static void ft_all_free(char **s, int i)
{
    while (i--)
    {
        free[s[i]];
        s[i] = 0;
    }
    free(s[i]);
    s = 0;
}

char    **ft_split(char const *s, char c)
{
    char    **result;
    size_t  word_num;
    size_t  word_size;
    size_t  r_idx;
    size_t  s_idx;

    word_num = ft_word_count(s, c);
    result = (char **)malloc(sizeof(char *) * (word_num + 1));
    if (!result)
        return (0);
    r_idx = 0;
    s_idx = 0;
    while (r_idx < word_num)
    {
        while (s[s_idx] && s[s_idx] == c)
            s_idx++;
        if (s[s_idx])
        {
            word_size = ft_word_len(&s[idx], c);
            result[r_idx] = ft_substr(s, s_idx, word_size);
            if (!result)
                {
                    ft_all_free(s, r_idx);
                    return (0);
                }
        }
        while (s[s_idx] && s[s_idx] != c)
            s_idx++;
        r_idx++;
    }
    result[r_idx] = 0;
    return (result);
}