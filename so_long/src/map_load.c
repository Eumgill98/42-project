/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:07:05 by hocjeong          #+#    #+#             */
/*   Updated: 2024/05/16 18:09:43 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	copy_line(char *line, t_sets *sets)
{
	t_list	*new;
	t_list	*last;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
	{
		freemap_lst(sets);
		return (-1);
	}
	new->next = 0;
	new->content = ft_strdup(line);
	if (!(new->content))
	{
		freemap_lst(sets);
		return (-1);
	}
	if (!(sets->map_lst))
		sets->map_lst = new;
	else
	{
		last = ft_lstlast(sets->map_lst);
		last->next = new;
	}
	return (0);
}

static int	make_map_lst(t_sets *sets)
{
	char	*line;

	line = get_next_line(sets->fd);
	if (!line)
		return (-1);
	while (line)
	{
		if (copy_line(line, sets) == -1)
		{
			free(line);
			return (-1);
		}
		sets->row++;
		free(line);
		line = get_next_line(sets->fd);
	}
	free(line);
	return (0);
}

static	int	lst_map_copy(t_sets *sets)
{
	int		idx;
	t_list	*curr;

	curr = sets->map_lst;
	idx = 0;
	while (curr)
	{
		sets->map[idx] = ft_strdup(curr->content);
		if (!(sets->map[idx]))
		{
			freemap_lst(sets);
			freemap(sets, idx);
			return (-1);
		}
		curr = curr->next;
		idx++;
	}
	sets->map[idx] = 0;
	freemap_lst(sets);
	return (0);
}

int	load_map(t_sets *sets)
{
	if (make_map_lst(sets) == -1)
		return (-1);
	sets->map = (char **)malloc(sizeof(char *) * (sets->row + 1));
	if (!(sets->map))
		return (-1);
	if (lst_map_copy(sets) == -1)
		return (-1);
	return (0);
}
