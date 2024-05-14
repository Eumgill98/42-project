/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:07:05 by hocjeong          #+#    #+#             */
/*   Updated: 2024/05/14 19:15:39 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	copy_line(char *line, t_maps *maps)
{
	t_list	*new;
	t_list	*last;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
	{
		freemap_lst(maps);
		return (-1);
	}
	new->next = 0;
	new->content = ft_strdup(line);
	if (!(maps->map_lst))
		maps->map_lst = new;
	else
	{
		last = ft_lstlast(maps->map_lst);
		last->next = new;
	}
	return (1);
}

static int	make_map_lst(t_maps *maps)
{
	char	*line;

	line = get_next_line(maps->fd);
	if (!line)
		return (-1);
	while (line)
	{
		if (copy_line(line, maps) == -1)
		{
			free(line);
			return (-1);
		}
		maps->row++;
		free(line);
		line = get_next_line(maps->fd);
	}
	free(line);
	return (1);
}

int	load_map(t_maps *maps)
{
	int		idx;
	t_list	*curr;

	if (make_map_lst(maps) == -1)
		return (-1);
	maps->map = (char **)malloc(sizeof(char *) * (maps->row + 1));
	if (!(maps->map))
		return (-1);
	curr = maps->map_lst;
	while (curr)
	{
		maps->map[idx] = ft_strdup(curr->content);
		if (!(maps->map[idx]))
		{
			freemap_lst(maps);
			freemap(maps, idx);
			return (-1);
		}
		curr = curr->next;
		idx++;
	}
	maps->map[idx] = 0;
	freemap_lst(maps);
	return (1);
}
