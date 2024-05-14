/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:54:38 by hocjeong          #+#    #+#             */
/*   Updated: 2024/02/29 15:16:46 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	s_idx;
	size_t	t_idx;

	if (!s)
		return (0);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (0);
	s_idx = 0;
	t_idx = 0;
	while (s[s_idx])
	{
		if (s_idx >= start && t_idx < len)
		{
			tmp[t_idx] = s[s_idx];
			t_idx++;
		}
		s_idx++;
	}
	tmp[t_idx] = 0;
	return (tmp);
}
