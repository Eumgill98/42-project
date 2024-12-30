/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_execve_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:09:21 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/22 16:14:32 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_exec.h"

static char	**find_path_split(t_env *envs_head)
{
	t_env	*tmp;
	char	**splited;

	tmp = envs_head;
	splited = NULL;
	while (tmp)
	{
		if (ft_strcmp(tmp->varname, "PATH") == 0)
		{
			splited = ft_split(tmp->value, ':');
			break ;
		}
		tmp = tmp->next;
	}
	return (splited);
}

static char	*joined_path_command(char *s1, char *s2)
{
	char	*tmp;
	char	*result;

	tmp = ft_strjoin(s1, "/");
	if (tmp == NULL)
	{
		mn_print_error(MALLOC, NULL);
		return (NULL);
	}
	result = ft_strjoin(tmp, s2);
	free(tmp);
	if (result == NULL)
	{
		mn_print_error(MALLOC, NULL);
		return (NULL);
	}
	return (result);
}

static char	*check_now_path(char *command)
{
	char	*cwd;
	char	*joined;

	cwd = NULL;
	cwd = getcwd(cwd, 0);
	if (cwd == NULL)
		return (NULL);
	joined = joined_path_command(cwd, command);
	if (joined == NULL)
	{
		mn_print_error(MALLOC, NULL);
		free(cwd);
		return (NULL);
	}
	if (access(joined, X_OK) == 0)
	{
		free(cwd);
		return (joined);
	}
	free(cwd);
	free(joined);
	return (NULL);
}

static char	*check_env_path(t_env *envs, char *command)
{
	char	*joined;
	char	**split_path;
	int		idx;

	split_path = find_path_split(envs);
	if (split_path == NULL)
	{
		mn_print_error(MALLOC, NULL);
		return (NULL);
	}
	idx = 0;
	while (split_path[idx])
	{
		joined = joined_path_command(split_path[idx++], command);
		if (access(joined, X_OK) == 0)
		{
			mn_free_split_path(split_path);
			return (joined);
		}
		free(joined);
	}
	mn_free_split_path(split_path);
	return (NULL);
}

char	*mn_check_access(t_env *envs, char *command)
{
	char	*path;

	if (command[0] == '/' && access(command, X_OK) == 0)
		return (ft_strdup(command));
	path = check_now_path(command);
	if (path)
		return (path);
	if (mn_check_in_env(envs, "PATH") == 0)
		return (NULL);
	path = check_env_path(envs, command);
	return (path);
}
