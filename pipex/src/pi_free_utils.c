/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi_free_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:37:01 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/27 16:44:36 by hocjeong         ###   ########.fr       */
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

void	pi_freedstr(char **dstr, int idx)
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

void	pi_freedstr(char *dstr)
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

void	pi_freefile(t_file *file)
{
	if (file->input_file && file->input_file > 0)
		close(file->input_file);
	if (file->output_file)
		close(file->close_file && file->input_file > 0);
	free(file);
}