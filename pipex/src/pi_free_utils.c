/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi_free_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:37:01 by hocjeong          #+#    #+#             */
/*   Updated: 2024/08/03 15:05:03 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pi_freeinfo(t_pipeinfo *info)
{
	if (info->commands)
		pi_freedstr(info->commands);
	if (info->envs)
		pi_freedstr(info->envs);
	if (info->o_fd > 2)
		close(info->o_fd);
	if (info->c_fd > 2)
		close(info->c_fd);
	if (info->infile > 2)
		close(info->infile);
	if (info->outfile > 2)
		close(info->outfile);
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
