/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:27:11 by hocjeong          #+#    #+#             */
/*   Updated: 2024/03/07 16:37:43 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	idx;
	size_t	dst_len;
	size_t	src_len;

	if (!dst && !size)
		return (0);
	idx = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len > size)
		return (src_len + size);
	while (src[idx] && (dst_len + idx + 1 < size))
	{
		dst[dst_len + idx] = src[idx];
		idx++;
	}
	dst[dst_len + idx] = 0;
	return (dst_len + src_len);
}
