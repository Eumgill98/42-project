/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:22:44 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/29 17:30:37 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**pi_command(int ac, char **av)
{
	int		idx;
	int		c_idx;
	char	**commands;

	commands = (char **)malloc(sizeof(char *) * (ac - 2));
	if (!commands)
		return (NULL);
	idx = 2;
	c_idx = 0;
	while (idx < ac - 1)
	{
		commands[c_idx] = ft_strdup(av[idx]);
		if (!commands[c_idx])
		{
			pi_freedstr_idx(commands, c_idx);
			return (NULL);
		}
		idx++;
		c_idx++;
	}
	commands[c_idx] = NULL;
	return (commands);
}
