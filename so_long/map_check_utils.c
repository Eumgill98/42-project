/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:33:54 by hocjeong          #+#    #+#             */
/*   Updated: 2024/05/16 17:45:35 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangular(t_sets *sets)
{
	int	tmp_col;
	int	idx;

	col = ft_strlen(map[0]);
	idx = 1;
	while (idx < sets->row)
	{
		if (col != ft_strlen(map[idx]))
			return (-1);
		idx++;
	}
	sets->col = col;
	return (0);
}

int	check_component(t_sets *sets)
{
	int	row;
	int	col;

	row = 0;
	while (row < sets->row)
	{
		col = 0;
		while (col < sets->col)
		{
			if (sets->map[row][col] == '1')
				continue ;
			else if (sets->map[row][col] == 'C')
				sets->map_flag->c_num++;
			else if (sets->map[row][col] == 'E')
				sets->map_flag->e_num++;
			else if (sets->map[row][col] == 'P')
				sets->map_flag->e_num++;
			else
				return (-1);
			col++;
		}
		row++;
	}
	return (0);
}

static int	col_wall_check(t_sets *sets, int check_row)
{
	int	col;

	col = 0;
	while (col < sets->col)
	{
		if (sets->map[check_row][col] != '1')
			return (-1);
		col++;
	}
	return (0);
}

static int	row_wall_check(t_sets *sets, int check_col)
{
	int	row;

	row = 0;
	while (row < sets->row)
	{
		if (sets->map[row][check_col] != '1')
			return (-1);
		row++;
	}
	return (0);
}

int	check_wall(t_sets *sets)
{
	if (col_wall_check(sets, 0) == -1)
		return (-1);
	if (col_wall_check(sets, sets->row - 1) == -1)
		return (-1);
	if (row_wall_check(sets, 0) == -1)
		return (-1);
	if (row_wall_check(sets, sets->col - 1) == -1)
		return (-1);
	return (0);
}
