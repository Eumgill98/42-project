/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi_info_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:37:01 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/26 20:16:00 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_h"

int	pi_init_info(int ac, char **av, char **env, t_pipeinfo *info)
{
	char	**commands;
	char	**envs;
	char	*path;

	commands = pi_command(ac, av);
	path = pi_env_find(env);
	if (!path)
		return (-1);
	envs = pi_env_split(path);
	free(path);
	info->commands = commands;
	info->envs = envs;
	if (!commands || !envs)
		return (-1);
	return (0);
}
