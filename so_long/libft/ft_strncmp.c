/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:23:55 by hocjeong          #+#    #+#             */
/*   Updated: 2024/03/04 15:39:28 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	idx = 0;
	if (!n)
		return (0);
	while (s1[idx] && s2[idx] && s1[idx] == s2[idx] && idx < n - 1)
		idx++;
	return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
}
