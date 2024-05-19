/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:48:15 by hocjeong          #+#    #+#             */
/*   Updated: 2024/05/19 17:56:43 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_visited(t_sets *sets)
{
	int	idx;
	int	col;

	idx = 0;
	while (idx < sets->row)
	{
		sets->visited[idx] = (char *)malloc(sizeof(char) * (sets->col + 1));
		if (!(sets->visited[idx]))
		{
			freevis(sets, idx);
			return (-1);
		}
		col = 0;
		while (col < sets->col)
		{
			sets->visited[idx][col] = '0';
			col++;
		}
		sets->visited[idx][col] = 0;
		idx++;
	}
	sets->visited[idx] = 0;
	return (0);
}

static int	map_dfs(int row, int col, t_sets *sets)
{
	int	tmp_c;

	tmp_c = 0;
	if (sets->map[row][col] == '1')
		return (0);
	if (sets->visited[row][col] == '0')
		sets->visited[row][col] = '1';
	else
		return (0);
	if (sets->map[row][col] == 'C')
		tmp_c++;
	tmp_c += map_dfs(row + 1, col, sets);
	tmp_c += map_dfs(row - 1, col, sets);
	tmp_c += map_dfs(row, col + 1, sets);
	tmp_c += map_dfs(row, col - 1, sets);
	return (tmp_c);
}

static int	find_player(t_sets *sets)
{
	int	row;
	int	col;

	row = 0;
	while (row < sets->row)
	{
		col = 0;
		while (col < sets->col)
		{
			if (sets->map[row][col] == 'P')
			{
				sets->player_r = row;
				sets->player_c = col;
				return (0);
			}
			col++;
		}
		row++;
	}
	return (-1);
}

int	check_path(t_sets *sets)
{
	sets->visited = (char **)malloc(sizeof(char *) * (sets->row + 1));
	if (!(sets->visited))
		return (-1);
	if (init_visited(sets) == -1)
		return (-1);
	find_player(sets);
	if (map_dfs(sets->player_r, sets->player_c, sets) != sets->map_flag->c_num)
		return (-1);
	return (0);
}
