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

static int	img_draw(t_sets *sets, char flag, int x, int y)
{
	mlx_put_image_to_window(\
		sets->mlx_ptr, sets->win_ptr, sets->g, x, y);
	if (flag == '1')
		mlx_put_image_to_window(\
			sets->mlx_ptr, sets->win_ptr, sets->w, x, y);
	else if (flag == 'P')
		mlx_put_image_to_window(\
			sets->mlx_ptr, sets->win_ptr, sets->p, x, y);
	else if (flag == 'C')
		mlx_put_image_to_window(\
			sets->mlx_ptr, sets->win_ptr, sets->c, x, y);
	else if (flag == 'E')
		mlx_put_image_to_window(\
			sets->mlx_ptr, sets->win_ptr, sets->e, x, y);
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
				col * sets->i_w, row * sets->i_h);
			col++;
		}
		row++;
	}
	return (0);
}
