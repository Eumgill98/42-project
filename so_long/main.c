/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:49:26 by hocjeong          #+#    #+#             */
/*   Updated: 2024/05/14 17:00:57 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

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
	t_sets	sets;

	sets.mlx_ptr = mlx_init();
	sets.win_ptr = mlx_new_window(sets.mlx_ptr, 600, 600, "my_mlx");
	mlx_key_hook(sets.win_ptr, esc_hook, &sets);
	mlx_loop(sets.mlx_ptr);
	return (0);
}
