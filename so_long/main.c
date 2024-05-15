/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:49:26 by hocjeong          #+#    #+#             */
/*   Updated: 2024/05/15 19:36:18 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
int	main(void)
{
	t_sets	sets;

	set_maps(&sets, "map/map1.ber");
	load_map(&sets);
	printf("row : %d\n", sets.row);
	printf("fd : %d\n", sets.fd);
	
	sets.mlx_ptr = mlx_init();
	sets.win_ptr = mlx_new_window(sets.mlx_ptr, 600, 600, "my_mlx");
	mlx_key_hook(sets.win_ptr, esc_hook, &sets);
	mlx_loop(sets.mlx_ptr);
	return (0);
}
