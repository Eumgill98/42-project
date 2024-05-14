/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:46:56 by hocjeong          #+#    #+#             */
/*   Updated: 2024/03/04 16:30:16 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	n_c;
	size_t			i;

	i = 0;
	tmp = (unsigned char *)s;
	n_c = (unsigned char)c;
	while (i < n)
	{
		if (tmp[i] == n_c)
			return (tmp + i);
		i++;
	}
	return (0);
}
