/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:28:22 by hocjeong          #+#    #+#             */
/*   Updated: 2024/05/19 18:49:07 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
static int	init_maps(t_maps *map_flag)
{
	t_maps	*maps;

	maps = (t_maps *)malloc(sizeof(t_maps));
	if (!maps)
		return (-1);
	maps->e_num = 0;
	maps->p_num = 0;
	maps->c_num = 0;
	map_flag = maps;
	return (0);
}

int	init_sets(t_sets *sets, char *map_path)
{
	sets->fd = open(map_path, O_RDONLY);
	if (sets->fd < 0)
		return (-1);
	sets->map_lst = NULL;
	sets->map = NULL;
	sets->visited = NULL;
	sets->row = 0;
	sets->col = 0;
	sets->player_r = 0;
	sets->player_c = 0;
	sets->i_h = 32;
	sets->i_w = 32;
	sets->g = mlx_xpm_file_to_image(sets->mlx_ptr, \
			"img/0.xpm", &sets->i_w, &sets->i_h);
	sets->w = mlx_xpm_file_to_image(sets->mlx_ptr, \
			"img/1.xpm", &sets->i_w, &sets->i_h);
	sets->c = mlx_xpm_file_to_image(sets->mlx_ptr, \
			"img/c.xpm", &sets->i_w, &sets->i_h);
	sets->e = mlx_xpm_file_to_image(sets->mlx_ptr, \
			"img/e.xpm", &sets->i_w, &sets->i_h);
	sets->p = mlx_xpm_file_to_image(sets->mlx_ptr, \
			"img/p.xpm", &sets->i_w, &sets->i_h);
	sets->map_flag = NULL;
	if (init_maps(sets->map_flag) == -1)
		return (-1);
	printf("%p\n", sets->map_flag);
	return (0);
}
