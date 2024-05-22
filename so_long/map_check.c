/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:47:57 by hocjeong          #+#    #+#             */
/*   Updated: 2024/05/22 17:59:32 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	check_map_flag(t_sets *sets)
{
	if (sets->map_flag.e_num != 1)
		return (-1);
	if (sets->map_flag.p_num != 1)
		return (-1);
	if (!(sets->map_flag.c_num))
		return (-1);
	return (0);
}

int	map_check(t_sets *sets)
{
	if (check_rectangular(sets) == -1)
		return (-1);
	if (check_component(sets) == -1)
		return (-1);
	if (check_map_flag(sets) == -1)
		return (-1);
	if (check_wall(sets) == -1)
		return (-1);
	if (check_path(sets) == -1)
		return (-1);
	sets->w_w = sets->col * sets->imgs.i_w;
	sets->w_h = sets->row * sets->imgs.i_h;
	sets->win_ptr = mlx_new_window(sets->mlx_ptr, \
		sets->w_w, sets->w_h, "game");
	if (!sets->win_ptr)
		return (-1);
	return (0);
}
