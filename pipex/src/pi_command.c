/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:22:44 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/24 19:38:19 by hocjeong         ###   ########.fr       */
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
			pi_freedstr(commands, c_idx);
			return (NULL);
		}
		idx++;
		c_idx++;
	}
	commands[idx] = NULL;
	return (commands);
}
