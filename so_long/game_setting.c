/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:28:22 by hocjeong          #+#    #+#             */
/*   Updated: 2024/05/16 17:16:40 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sets(t_sets *sets, char *map_path)
{
	sets->fd = open(map_path, O_RDONLY);
	sets->map_lst = NULL;
	sets->map = NULL;
	sets->row = 0;
	sets->col = 0;
	sets->map_flag->e_num = 0;
	sets->map_flag->p_num = 0;
	sets->map_flag->c_num = 0;
}
