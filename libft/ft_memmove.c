/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:31:00 by hocjeong          #+#    #+#             */
/*   Updated: 2024/03/04 16:09:14 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*t_dest;
	unsigned char	*t_src;

	if (dest > src)
	{
		t_dest = (unsigned char *)dest;
		t_src = (unsigned char *)src;
		while (n-- > 0)
			t_dest[n] = t_src[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
