/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 20:18:26 by hocjeong          #+#    #+#             */
/*   Updated: 2024/03/14 18:05:03 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_ft_strlen(char *str)
{
	size_t	idx;

	idx = 0;
	if (!str)
		return (0);
	while (str[idx])
		idx++;
	return (idx);
}

char	*gnl_ft_strjoin(char *s1, char *s2)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	tmp = (char *)malloc(sizeof(char) * (gnl_ft_strlen(s1) + gnl_ft_strlen(s2) + 1));
	if (!tmp)
		return (0);
	i = -1;
	j = 0;
	while (s1[++i])
		tmp[i] = s1[i];
	while (s2[j])
		tmp[i++] = s2[j++];
	tmp[gnl_ft_strlen(s1) + gnl_ft_strlen(s2)] = 0;
	free(s1);
	return (tmp);
}

char	*gnl_ft_strchr(char *str, int c)
{
	if (!str)
		return (0);
	if (c == 0)
		return (&str[gnl_ft_strlen(str)]);
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (0);
}
