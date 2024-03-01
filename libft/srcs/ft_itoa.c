#include "libft.h"

static size_t   ft_total_len(int n, int *minus)
{
    size_t  len;

    len = 0;
    if (n < 0)
    {
        if (n == -2147483648)
        {
            *minus = -1;
            return (10);
        }
        else
        {
            *minus = 1;
            n = -n;
        }
    }
    else if (n == 0)
        return (1);
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    return (len);
}

static  void    ft_allocate_str(char *str, size_t total_len, int n)
{
    size_t  idx;

    idx = 0;
    if (n == 0)
        str[idx] = 0;
    while (n != 0)
    {
        str[total_len - idx - 1] = n % 10 + '0';
        n /= 10;
        idx++;
    }
}

char    *ft_itoa(int n)
{
    char    *result;
    size_t  total_len;
    int         minus;

    minus = 0;
    total_len = ft_total_len(n, &minus);
    result = (char *)malloc(sizeof(char) * (total_len + minus + 1));
    if(!result)
        return(0);
    result[total_len + minus] = 0;
    if (n == -2147483648)
    {
        result[10] = '8';
        n = 214748364;
        result[0] = '-';
        len--;
    }
    else if (minus == 1)
    {
        str[0] = '-';
        n = -n;
    }
    ft_allocate_str(&result[minus], total_len, n);
    return (result);
}