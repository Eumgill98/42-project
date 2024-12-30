/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_free_split_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:37:01 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/22 16:39:54 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_exec.h"

static int	len_split_path(char **split_path)
{
	int	len;

	len = 0;
	while (split_path[len])
		len++;
	return (len);
}

void	mn_free_split_path(char **split_path)
{
	int	len;
	int	idx;

	len = len_split_path(split_path);
	idx = 0;
	while (idx < len)
	{
		free(split_path[idx]);
		idx++;
	}
	free(split_path);
}
