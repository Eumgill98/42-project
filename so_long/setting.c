/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:28:22 by hocjeong          #+#    #+#             */
/*   Updated: 2024/05/14 18:54:34 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_maps(t_maps *maps, char *map_path)
{
	maps->fd = open(map_path, O_RDONLY);
	maps->map_lst = NULL;
	maps->map = NULL;
	maps->col = 0;
}
