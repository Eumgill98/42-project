/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:40:08 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/24 20:04:15 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*pi_path_join(char *s1, char *s2)
{
	char	*tmp;
	char	*result;

	tmp = ft_strjoin(s1, "/");
	if (!tmp)
		return (NULL);
	result = ft_strjoin(tmp, s2);
	free(tmp);
	if (!result)
		return (NULL);
	return (result);
}

char	*pi_env_find(char **env)
{
	while (*env)
	{
		if (ft_strncmp("PATH", *env, 4) == 0)
			return (*env + 5);
		env++;
	}
	return (NULL);
}

char	**pi_env_split(char *path)
{
	char	**s_path;

	s_path = ft_split(path, ':');
	if (!s_path)
		return (NULL);
	return (s_path);
}

char	*pi_env_access(char **envs, char *command)
{
	int		idx;
	char	*joined;

	idx = 0;
	while (envs[idx])
	{
		joined = pi_path_join(envs[idx], command);
		if (!joined)
			return (NULL);
		if (access(joined, X_OK) == 0)
		{
			free(joined);
			return (envs[idx]);
		}
		idx++;
		free(joined);
	}
	return (NULL);
}
