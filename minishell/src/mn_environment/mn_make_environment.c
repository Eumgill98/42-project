/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_make_environment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:43:51 by hocjeong          #+#    #+#             */
/*   Updated: 2024/11/27 21:17:06 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_environment.h"

static void	init_new(t_environment *new)
{
	new->envs = NULL;
	new->exports = NULL;
}

t_environment	*mn_make_environment(char **envp)
{
	t_environment	*new;

	new = (t_environment *)malloc(sizeof(t_environment));
	if (!new)
		return (NULL);
	init_new(new);
	if (mn_make_env_lst(envp, &new->envs, 0) == -1)
	{
		mn_destroy_env_lst(new->envs);
		free(new);
		return (NULL);
	}
	if (mn_make_env_lst(envp, &new->exports, 1) == -1)
	{
		mn_destroy_env_lst(new->exports);
		free(new);
		return (NULL);
	}
	return (new);
}
