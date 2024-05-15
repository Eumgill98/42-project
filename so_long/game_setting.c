/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:28:22 by hocjeong          #+#    #+#             */
/*   Updated: 2024/05/15 17:17:48 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_maps(t_sets *sets, char *map_path)
{
	sets->fd = open(map_path, O_RDONLY);
	sets->map_lst = NULL;
	sets->map = NULL;
	sets->row = 0;
}
