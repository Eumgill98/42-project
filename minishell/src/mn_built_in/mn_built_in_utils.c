/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_built_in_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:57:03 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/15 20:17:45 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_built_in.h"

static char	*home_directroy(char *path, char *homepath)
{
	char	*joint_path;

	if (ft_strlen(path) > 1)
	{
		joint_path = ft_strjoin(homepath, &path[1]);
		if (joint_path == NULL)
			return (NULL);
		return (joint_path);
	}
	else
		return (ft_strdup(homepath));
}

char	*get_directory_path(char *path)
{
	char	*homepath;

	homepath = getenv("HOME");
	if (path && path[0] == '~')
		return (home_directroy(path, homepath));
	return (ft_strdup(path));
}
