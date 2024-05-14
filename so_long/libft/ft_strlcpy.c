/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:57:10 by hocjeong          #+#    #+#             */
/*   Updated: 2024/03/04 15:43:32 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	idx;

	if (!size)
		return (ft_strlen(src));
	idx = 0;
	while (src[idx] && idx + 1 < size)
	{
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = 0;
	return (ft_strlen(src));
}
