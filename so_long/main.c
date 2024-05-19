/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:49:26 by hocjeong          #+#    #+#             */
/*   Updated: 2024/05/19 18:34:01 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

/*static int	check_extension(const char *filename, const char *extension)
{
	int filename_len;
	int	extension_len;

	filename_len = ft_strlen(filename);
	extension_len = ft_strlen(filename);
	if (filename_len < extension_len) 
		return (-1);
	if (ft_strncmp(filename + filename_len - extension_len, extension, extension_len))
		return (-1);
	return (0);
}*/

int	main(int ac, char **av)
{
	t_sets	sets;

	if (ac == 2)
	{
		fflush(stdout);
		//if (check_extension(av[1], ".ber") == -1)
			//return (-1);	
		sets.mlx_ptr = mlx_init();
		sets.win_ptr = mlx_new_window(sets.mlx_ptr, 600, 600, "my_mlx");
		init_sets(&sets, av[1]);
		load_map(&sets);
		if (map_check(&sets) == -1)
			return (-1);
		map_draw(&sets);
		mlx_key_hook(sets.win_ptr, esc_hook, &sets);
		mlx_loop(sets.mlx_ptr);
	}
	return (0);
}
