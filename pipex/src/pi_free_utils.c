/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi_free_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:37:01 by hocjeong          #+#    #+#             */
/*   Updated: 2024/08/01 19:25:31 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pi_freeinfo(t_pipeinfo *info)
{
	if (info->commands)
		pi_freedstr(info->commands);
	if (info->envs)
		pi_freedstr(info->envs);
	free(info);
}

void	pi_freedstr_idx(char **dstr, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		free(dstr[i]);
		dstr[i] = NULL;
		i++;
	}
	free(dstr);
}

void	pi_freedstr(char **dstr)
{
	int	i;

	i = 0;
	while (dstr[i])
	{
		free(dstr[i]);
		dstr[i] = NULL;
		i++;
	}
	free(dstr);
}

void	pi_freepipe(int *fd)
{
	if (fd[0] > 2)
		close(fd[0]);
	if (fd[1] > 2)
		close(fd[0]);
}
