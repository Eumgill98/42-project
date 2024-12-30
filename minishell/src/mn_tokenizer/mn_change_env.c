/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_change_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 06:52:32 by hocjeong          #+#    #+#             */
/*   Updated: 2024/11/24 06:53:15 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

static void	free_mn_change_var(char *substr, char *joined_str, char *tmp)
{
	if (substr)
		free(substr);
	if (joined_str)
		free(joined_str);
	if (tmp)
		free(tmp);
}

static int	init_mn_change(int *idx, char **joined_str, char *content)
{
	if (!content)
		return (0);
	*joined_str = NULL;
	*idx = 0;
	if (content[*idx] == '"')
		(*idx)++;
	return (1);
}

static char	*make_substr(char *content, int *idx, t_env *envs)
{
	char	*substr;

	if (content[*idx] == '$')
		substr = resolve_env_var(content, idx, envs);
	else
	{
		substr = extract_substr(content, idx);
		(*idx)++;
	}
	return (substr);
}

char	*mn_change_env(char *content, t_env	*envs)
{
	char	*joined_str;
	char	*tmp;
	char	*substr;
	int		idx;

	if (!init_mn_change(&idx, &joined_str, content))
		return (NULL);
	while (content[idx] && content[idx] != '"')
	{
		substr = make_substr(content, &idx, envs);
		tmp = ft_strjoin(joined_str, substr);
		if (!tmp || !substr)
		{
			free_mn_change_var(substr, joined_str, tmp);
			return (NULL);
		}
		free_mn_change_var(substr, joined_str, NULL);
		joined_str = tmp;
	}
	return (joined_str);
}
