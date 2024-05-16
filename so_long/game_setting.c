/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:28:22 by hocjeong          #+#    #+#             */
/*   Updated: 2024/05/16 18:23:05 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_maps(t_maps *maps)
{
	maps = (t_maps *)malloc(sizeof(t_maps));
	if (!maps)
		return (-1);
	maps->e_num = 0;
	maps->p_num = 0;
	maps->c_num = 0;
	return (0);
}

int	init_sets(t_sets *sets, char *map_path)
{
	sets->fd = open(map_path, O_RDONLY);
	sets->map_lst = NULL;
	sets->map = NULL;
	sets->row = 0;
	sets->col = 0;
	if (init_maps(sets->map_flag) == -1)
		return (-1);
	return (0);
}
