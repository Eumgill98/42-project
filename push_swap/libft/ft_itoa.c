/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:19:06 by hocjeong          #+#    #+#             */
/*   Updated: 2024/03/03 16:37:14 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_total_len(int n, int *minus)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			*minus = 1;
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
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	ft_allocate_num(char *str, size_t total_len, int n)
{
	size_t	idx;

	idx = 0;
	if (!n)
		str[idx] = '0';
	while (n)
	{
		str[total_len - idx - 1] = n % 10 + '0';
		n /= 10;
		idx++;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	total_len;
	int		minus;

	minus = 0;
	total_len = ft_total_len(n, &minus);
	result = (char *)malloc(sizeof(char) * (total_len + minus + 1));
	if (!result)
		return (0);
	result[total_len + minus] = 0;
	if (n == -2147483648)
	{
		result[10] = '8';
		n = 214748364;
		result[0] = '-';
		total_len--;
	}
	else if (minus)
	{
		result[0] = '-';
		n = -n;
	}
	ft_allocate_num(&result[minus], total_len, n);
	return (result);
}
