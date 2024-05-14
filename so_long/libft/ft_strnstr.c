/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:57:14 by hocjeong          #+#    #+#             */
/*   Updated: 2024/03/05 18:40:58 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b_idx;
	size_t	l_idx;

	b_idx = 0;
	if (!*little)
		return ((char *)big);
	while (b_idx < len && big[b_idx])
	{
		l_idx = 0;
		while (big[b_idx + l_idx] == little[l_idx] && b_idx + l_idx < len)
		{
			l_idx++;
			if (!little[l_idx])
				return ((char *)&big[b_idx]);
		}
		b_idx++;
	}
	return (0);
}
