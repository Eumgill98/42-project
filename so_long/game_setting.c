/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:28:22 by hocjeong          #+#    #+#             */
/*   Updated: 2024/05/20 16:10:16 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	open_map_file(t_sets *sets, char *map_path)
{
		sets->fd = open(map_path, O_RDONLY);
		if (sets->fd < 0)
			return (-1);
	return (0);
}

static int	load_image_file(t_sets *sets)
{
	sets->g = mlx_xpm_file_to_image(sets->mlx_ptr, \
		"img/0.xpm", &sets->i_w, &sets->i_h);
    if (!sets->g) 
		return (-1);
    sets->w = mlx_xpm_file_to_image(sets->mlx_ptr, \
		"img/1.xpm", &sets->i_w, &sets->i_h);
    if (!sets->w) 
		return (-1);
    sets->c = mlx_xpm_file_to_image(sets->mlx_ptr, \
		"img/c.xpm", &sets->i_w, &sets->i_h);
    if (!sets->c) 
		return (-1);
    sets->e = mlx_xpm_file_to_image(sets->mlx_ptr, \
		"img/e.xpm", &sets->i_w, &sets->i_h);
    if (!sets->e) 
		return (-1);
    sets->p = mlx_xpm_file_to_image(sets->mlx_ptr, \
		"img/p.xpm", &sets->i_w, &sets->i_h);
    if (!sets->p) 
		return (-1);
	return (0);
}

static void	initialize_sets(t_sets *sets)
{
	sets->map_lst = NULL;
	sets->map = NULL;
	sets->visited = NULL;
	sets->row = 0;
	sets->col = 0;
	sets->player_r = 0;
	sets->player_c = 0;
	sets->i_h = 32;
	sets->i_w = 32;
	sets->map_flag.e_num = 0;
	sets->map_flag.p_num = 0;
	sets->map_flag.c_num = 0;
}

int	init_sets(t_sets *sets, char *map_path)
{
	if (open_map_file(sets, map_path) == -1)
		return (-1);
	initialize_sets(sets);
	if (load_image_file(sets) == -1)
		return (-1);
	return (0);
}
