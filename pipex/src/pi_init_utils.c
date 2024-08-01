/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi_init_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:37:01 by hocjeong          #+#    #+#             */
/*   Updated: 2024/08/01 19:33:27 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pi_dstrlen(char **dstr)
{
	int	len;

	len = 0;
	while (dstr[len])
		len++;
	return (len);
}

t_pipeinfo	*pi_init_info_allocate(void)
{
	t_pipeinfo	*tmp;

	tmp = (t_pipeinfo *)malloc(sizeof(t_pipeinfo));
	if (!tmp)
		return (NULL);
	tmp->commands = NULL;
	tmp->envs = NULL;
	tmp->num_commands = 0;
	return (tmp);
}

t_pipeinfo	*pi_init_info(int ac, char **av, char **env)
{
	char		**commands;
	char		**envs;
	char		*path;
	t_pipeinfo	*t_info;

	t_info = pi_init_info_allocate();
	if (!t_info)
		return (NULL);
	path = pi_env_find(env);
	if (!path)
		return (NULL);
	envs = pi_env_split(path);
	commands = pi_command(ac, av);
	t_info->commands = commands;
	t_info->envs = envs;
	if (!commands || !envs)
	{
		pi_freeinfo(t_info);
		return (NULL);
	}
	t_info->num_commands = pi_dstrlen(commands);
	return (t_info);
}
