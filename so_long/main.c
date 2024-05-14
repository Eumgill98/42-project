/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:49:26 by hocjeong          #+#    #+#             */
/*   Updated: 2024/05/14 21:52:26 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	esc_hook(int keycode, t_sets *sets)
{
	if (keycode == 0xFF1B)
	{
		mlx_destroy_window(sets->mlx_ptr, sets->win_ptr);
		exit(0);
	}
	return (0);
}

int	main(void)
{
	//t_sets	sets;
	t_maps		maps;
	char	**tmp;
	int	idx;

	set_maps(&maps, "map/map1.ber");
	load_map(&maps);
	printf("row : %d\n", maps.row);
	printf("fd : %d\n", maps.fd);
	tmp = maps.map;
	idx = 0;
	while (idx < maps.row)
	{
		printf("%s", tmp[idx]);
		idx++;
	}
	
	//sets.mlx_ptr = mlx_init();
	//sets.win_ptr = mlx_new_window(sets.mlx_ptr, 600, 600, "my_mlx");
	//mlx_key_hook(sets.win_ptr, esc_hook, &sets);
	//mlx_loop(sets.mlx_ptr);
	return (0);
}
