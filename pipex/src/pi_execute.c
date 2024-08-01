/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:41:33 by hocjeong          #+#    #+#             */
/*   Updated: 2024/08/01 16:36:54 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pi_execute(t_pipeinfo *info, char *command)
{
	char	*path;
	char	**commands;
	int		flag;

	commands = ft_split(command, ' ');
	path = pi_env_access(info->envs, commands[0]);
	if (!path || !commands)
	{
		if (path)
			free(path);
		if (commands)
			pi_freedstr(commands);
		return (-1);
	}
	flag = execve(path, commands, NULL);
	free(path);
	pi_freedstr(commands);
	if (flag == -1)
		return (-1);
	return (0);
}
