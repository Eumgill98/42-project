/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi_free_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:37:01 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/24 20:16:00 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	pi_dstrlen(char **dstr)
{
	int	len;

	len = 0;
	while (dstr[len])
		len++;
	return (len);
}

void	pi_freeinfo(t_pipeinfo *info)
{
	if (info->commands)
		pi_freedstr(info->commands, pi_dstrlen(info->commands));
	if (info->envs)
		pi_freedstr(info->envs, pi_dstrlen(info->envs));
}

void	pi_freedstr(char **dstr, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		free(dstr[idx]);
		dstr[idx] = NULL;
		i++;
	}
}
