/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:30:31 by hocjeong          #+#    #+#             */
/*   Updated: 2024/05/19 17:57:55 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_draw(t_sets *sets, int x, int y)
{
	if (sets->player.direction == 0)
		mlx_put_image_to_window(\
			sets->mlx_ptr, sets->win_ptr, sets->imgs.back, x, y);
	else if (sets->player.direction == 1)
		mlx_put_image_to_window(\
			sets->mlx_ptr, sets->win_ptr, sets->imgs.right, x, y);
	else if (sets->player.direction == 2)
		mlx_put_image_to_window(\
			sets->mlx_ptr, sets->win_ptr, sets->imgs.front, x, y);
	else
		mlx_put_image_to_window(\
			sets->mlx_ptr, sets->win_ptr, sets->imgs.left, x, y);
	return (0);
}

int	img_draw(t_sets *sets, char flag, int x, int y)
{
	if (flag == '1')
		mlx_put_image_to_window(\
			sets->mlx_ptr, sets->win_ptr, sets->imgs.w, x, y);
	else if (flag == 'P')
		player_draw(sets, x, y);
	else if (flag == 'C')
		mlx_put_image_to_window(\
			sets->mlx_ptr, sets->win_ptr, sets->imgs.c, x, y);
	else if (flag == 'E')
	{
		mlx_put_image_to_window(\
			sets->mlx_ptr, sets->win_ptr, sets->imgs.e, x, y);
		sets->player.door_r = y / sets->imgs.i_w;
		sets->player.door_c = x / sets->imgs.i_h;
	}
	else if (flag == 'O')
		mlx_put_image_to_window(\
			sets->mlx_ptr, sets->win_ptr, sets->imgs.e_open, x, y);
	else
		mlx_put_image_to_window(\
			sets->mlx_ptr, sets->win_ptr, sets->imgs.g, x, y);
	return (0);
}

int	map_draw(t_sets *sets)
{
	int	row;
	int	col;

	row = 0;
	while (sets->map[row])
	{
		col = 0;
		while (sets->map[row][col])
		{
			img_draw(sets, sets->map[row][col], \
				col * sets->imgs.i_w, row * sets->imgs.i_h);
			col++;
		}
		row++;
	}
	return (0);
}
