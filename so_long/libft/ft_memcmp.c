/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:25:23 by hocjeong          #+#    #+#             */
/*   Updated: 2024/02/27 18:44:05 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*t_s1;
	unsigned char	*t_s2;
	size_t			idx;

	t_s1 = (unsigned char *)s1;
	t_s2 = (unsigned char *)s2;
	idx = 0;
	if (!n)
		return (0);
	while (t_s1[idx] == t_s2[idx] && idx < n - 1)
		idx++;
	return (t_s1[idx] - t_s2[idx]);
}
