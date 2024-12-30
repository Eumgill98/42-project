/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:03:24 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/22 16:05:54 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_exec.h"

static char	**merge_command(t_process *now)
{
	char	**result;
	int		idx;
	t_arg	*tmp;
	int		len;

	len = mn_arglen(now->args) + 1;
	tmp = now->args;
	result = (char **)malloc(sizeof(char *) * (len + 1));
	if (result == NULL)
		return (NULL);
	idx = 0;
	result[idx] = now->command;
	idx++;
	while (tmp)
	{
		result[idx] = tmp->arg;
		idx++;
		tmp = tmp->next;
	}
	result[idx] = NULL;
	return (result);
}

static void	is_directory(char *command, t_mn_setting *setting)
{
	struct stat	path_stat;
	int			flag;

	flag = 0;
	if (stat(command, &path_stat) == 0)
		flag = S_ISDIR(path_stat.st_mode);
	if (flag)
	{
		mn_print_error(IS_DIRECTORY, command);
		mn_setting_exit(setting, 126);
	}
}

static void	not_path(t_mn_setting *setting, char *path, char **commands)
{
	if (path == NULL)
	{
		mn_print_error(NOT_COMMAND, commands[0]);
		free(commands);
		mn_setting_exit(setting, 127);
	}
}

int	mn_execve(t_process *now, t_mn_setting *setting)
{
	char	**commands;
	char	*path;
	int		flag;

	if (now->built_in_type != NOT_BUILT_IN)
		return (mn_do_built_in(setting, now));
	else
	{
		if (now->command)
			is_directory(now->command, setting);
		commands = merge_command(now);
		if (commands == NULL)
		{
			mn_print_error(MALLOC, NULL);
			return (-1);
		}
		path = mn_check_access(setting->environment->envs, commands[0]);
		not_path(setting, path, commands);
		flag = execve(path, commands, setting->envp);
		free(path);
		free(commands);
		return (flag);
	}
}
