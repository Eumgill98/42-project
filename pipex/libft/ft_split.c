/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:33:57 by hocjeong          #+#    #+#             */
/*   Updated: 2024/03/06 15:52:53 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	int	idx;
	int	count;

	idx = 0;
	count = 0;
	while (s[idx])
	{
		while (s[idx] && s[idx] == c)
			idx++;
		if (s[idx])
			count++;
		while (s[idx] && s[idx] != c)
			idx++;
	}
	return (count);
}

static int	ft_word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static	void	ft_all_free(char **result, int i)
{
	while (i--)
	{
		free(result[i]);
		result[i] = 0;
	}
}

static int	ft_allocate_str(char **result, char *s, char c, int r_idx)
{
	int		word_len;
	int		idx;
	char	*tmp;

	idx = 0;
	word_len = ft_word_len(s, c);
	tmp = (char *)malloc(sizeof(char) * (word_len + 1));
	if (!tmp)
	{
		ft_all_free(result, r_idx);
		return (0);
	}
	while (idx < word_len)
	{
		tmp[idx] = s[idx];
		idx++;
	}
	tmp[idx] = 0;
	result[r_idx] = tmp;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	char	*tmp;
	int		word_num;
	int		idx;

	word_num = ft_word_count(s, c);
	result = (char **)malloc(sizeof(char *) * (word_num + 1));
	if (!result)
		return (0);
	idx = 0;
	tmp = (char *)s;
	while (idx < word_num)
	{
		while (*tmp && *tmp == c)
			tmp++;
		if (*tmp && !ft_allocate_str(result, tmp, c, idx))
			return (0);
		while (*tmp && *tmp != c)
			tmp++;
		idx++;
	}
	result[idx] = 0;
	return (result);
}
