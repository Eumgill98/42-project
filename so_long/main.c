/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:49:26 by hocjeong          #+#    #+#             */
/*   Updated: 2024/05/20 17:54:33 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_extension(const char *filename, const char *extension)
{
	int	filename_len;
	int	extension_len;

	filename_len = ft_strlen(filename);
	extension_len = ft_strlen(extension);
	if (filename_len < extension_len)
		exit(0);
	filename += filename_len - extension_len;
	while (*extension)
	{
		if (*filename != *extension)
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		filename++;
		extension++;
	}
}

int	main(int ac, char **av)
{
	t_sets	sets;

	if (ac == 2)
	{
		check_extension(av[1], ".ber");
		if (init_sets(&sets, av[1]) == -1)
			error_exit(&sets);
		load_map(&sets);
		if (map_check(&sets) == -1)
			error_exit(&sets);
		sets.win_ptr = mlx_new_window(sets.mlx_ptr, sets.w_w, sets.w_h, "my_mlx");
		if (!sets.win_ptr)
			error_exit(&sets);
		map_draw(&sets);
		mlx_key_hook(sets.win_ptr, key_hook, &sets);
		mlx_loop(sets.mlx_ptr);
	}
}
