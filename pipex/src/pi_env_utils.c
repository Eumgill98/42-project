/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:40:08 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/24 16:53:33 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*pi_env(char **env)
{
	while (*env)
	{
		if (ft_strncmp("PATH", *env, 4) == 0)
			return (*env + 5);
		env++;
	}
	return (NULL);
}

char	**pi_env_split(char *path)
{
	char	**s_path;

	s_path = ft_spit(path, ":");
	if (!s_path)
		return (NULL);
	return (s_path);
}
