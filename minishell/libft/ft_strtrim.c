/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:07:13 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/05 11:58:58 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*result;

	if (!s1)
		return (0);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strrchr(set, s1[start]))
		start++;
	while (end >= 0 && ft_strrchr(set, s1[end]))
		end--;
	if (start > end)
		return (ft_strdup(""));
	result = ft_substr(s1, start, end - start + 1);
	return (result);
}
