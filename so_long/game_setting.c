/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:28:22 by hocjeong          #+#    #+#             */
/*   Updated: 2024/05/20 17:53:21 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	load_resource_image(t_sets *sets)
{
	sets->imgs.g = mlx_xpm_file_to_image(sets->mlx_ptr, \
		"img/0.xpm", &sets->imgs.i_w, &sets->imgs.i_h);
	if (!sets->imgs.g)
		return (-1);
	sets->imgs.w = mlx_xpm_file_to_image(sets->mlx_ptr, \
		"img/1.xpm", &sets->imgs.i_w, &sets->imgs.i_h);
	if (!sets->imgs.w)
		return (-1);
	sets->imgs.c = mlx_xpm_file_to_image(sets->mlx_ptr, \
		"img/c.xpm", &sets->imgs.i_w, &sets->imgs.i_h);
	if (!sets->imgs.c)
		return (-1);
	sets->imgs.e = mlx_xpm_file_to_image(sets->mlx_ptr, \
		"img/e.xpm", &sets->imgs.i_w, &sets->imgs.i_h);
	if (!sets->imgs.e)
		return (-1);
	sets->imgs.e_open = mlx_xpm_file_to_image(sets->mlx_ptr, \
		"img/e_open.xpm", &sets->imgs.i_w, &sets->imgs.i_h);
	if (!sets->imgs.e_open)
		return (-1);
	return (0);
}

static int	load_player_image(t_sets *sets)
{
	sets->imgs.back = mlx_xpm_file_to_image(sets->mlx_ptr, \
		"img/back.xpm", &sets->imgs.i_w, &sets->imgs.i_h);
	if (!sets->imgs.back)
		return (-1);
	sets->imgs.right = mlx_xpm_file_to_image(sets->mlx_ptr, \
		"img/right.xpm", &sets->imgs.i_w, &sets->imgs.i_h);
	if (!sets->imgs.right)
		return (-1);
	sets->imgs.front = mlx_xpm_file_to_image(sets->mlx_ptr, \
		"img/front.xpm", &sets->imgs.i_w, &sets->imgs.i_h);
	if (!sets->imgs.front)
		return (-1);
	sets->imgs.left = mlx_xpm_file_to_image(sets->mlx_ptr, \
		"img/left.xpm", &sets->imgs.i_w, &sets->imgs.i_h);
	if (!sets->imgs.left)
		return (-1);
	return (0);
}

static void	initialize_sets(t_sets *sets)
{
	sets->mlx_ptr = NULL;
	sets->win_ptr = NULL;
	sets->map_lst = NULL;
	sets->map = NULL;
	sets->visited = NULL;
	sets->row = 0;
	sets->col = 0;
	sets->imgs.i_h = 0;
	sets->imgs.i_w = 0;
	sets->w_w = 0;
	sets->w_h = 0;
	sets->map_flag.e_num = 0;
	sets->map_flag.p_num = 0;
	sets->map_flag.c_num = 0;
}

static void	initialize_player_info(t_sets *sets)
{
	sets->player.player_r = 0;
	sets->player.player_c = 0;
	sets->player.collected = 0;
	sets->player.direction = 2;
	sets->player.door_r = 0;
	sets->player.door_c = 0;
	sets->player.door_open = 0;
	sets->player.movement = 0;
}

int	init_sets(t_sets *sets, char *map_path)
{
	initialize_sets(sets);
	initialize_player_info(sets);
	sets->fd = open(map_path, O_RDONLY);
	if (sets->fd < 0)
		return (-1);
	sets->mlx_ptr = mlx_init();
	if (!sets->mlx_ptr)
		return (-1);
	if (load_resource_image(sets) == -1)
		return (-1);
	if (load_player_image(sets) == -1)
		return (-1);
	return (0);
}
