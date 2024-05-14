/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:49:26 by hocjeong          #+#    #+#             */
/*   Updated: 2024/05/13 17:39:19 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	esc_hook(int keycode, t_vars *vars)
{
	if (keycode == 0xFF1B)
	{
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_img	img;

	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, 600, 600, "my_mlx");
	img.img_ptr = mlx_xpm_file_to_image(vars.mlx_ptr, "img/1.xpm", &img.width, &img.height);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.size_line, &img.endian);
	mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, img.img_ptr, 0, 0);
	mlx_key_hook(vars.win_ptr, esc_hook, &vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}
