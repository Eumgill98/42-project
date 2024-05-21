/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:07:33 by hocjeong          #+#    #+#             */
/*   Updated: 2024/05/21 20:47:31 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freemap_lst(t_sets *sets)
{
	t_list	*curr;
	t_list	*next;

	curr = sets->map_lst;
	while (curr)
	{
		next = curr->next;
		free(curr->content);
		free(curr);
		curr = next;
	}
	free(curr);
}

void	freemap(t_sets *sets, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		free(sets->map[i]);
		sets->map[i] = 0;
		i++;
	}
	free(sets->map);
	sets->map = 0;
}

void	freevis(t_sets *sets, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		free(sets->visited[i]);
		sets->visited[i] = 0;
		i++;
	}
	free(sets->visited);
	sets->visited = 0;
}
