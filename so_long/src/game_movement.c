/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:43:20 by hocjeong          #+#    #+#             */
/*   Updated: 2024/05/22 17:24:06 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	clear_game(t_sets *sets)
{
	all_freeimg(sets);
	mlx_destroy_window(sets->mlx_ptr, sets->win_ptr);
	mlx_destroy_display(sets->mlx_ptr);
	free(sets->mlx_ptr);
	freemap(sets, sets->row);
	freevis(sets, sets->row);
	close(sets->fd);
	exit(0);
}

static int	check_values(t_sets *sets, char c, int t_row, int t_col)
{
	if (c == '1')
		return (0);
	else if (c == 'C')
	{
		sets->player.collected++;
		sets->map[t_row][t_col] = '0';
		if (sets->player.collected == sets->map_flag.c_num)
		{
			img_draw(sets, 'O', \
				sets->player.door_c * sets->imgs.i_w, \
				sets->player.door_r * sets->imgs.i_h);
			sets->player.door_open = 1;
		}
	}
	else if (c == 'E' && sets->player.door_open)
		clear_game(sets);
	else if (c == 'E' && !sets->player.door_open)
		return (0);
	return (1);
}

static void	update_x_y(t_sets *sets, int keycode, int *t_row, int *t_col)
{
	if (keycode == KEY_W)
	{
		sets->player.direction = 0;
		*t_row = *t_row - 1;
	}
	else if (keycode == KEY_A)
	{
		sets->player.direction = 1;
		*t_col = *t_col + 1;
	}
	else if (keycode == KEY_S)
	{
		sets->player.direction = 2;
		*t_row = *t_row + 1;
	}
	else if (keycode == KEY_D)
	{
		sets->player.direction = 3;
		*t_col = *t_col - 1;
	}
}

int	key_hook(int keycode, t_sets *sets)
{
	int	t_row;
	int	t_col;

	if (keycode == KEY_ESC)
		clear_game(sets);
	else if (keycode == KEY_W || keycode == KEY_A || \
		keycode == KEY_S || keycode == KEY_D)
	{
		t_row = sets->player.player_r;
		t_col = sets->player.player_c;
		update_x_y(sets, keycode, &t_row, &t_col);
		if (!check_values(sets, sets->map[t_row][t_col], t_row, t_col))
			return (0);
		img_draw(sets, '0', sets->player.player_c * sets->imgs.i_w, \
		sets->player.player_r * sets->imgs.i_h);
		player_draw(sets, t_col * sets->imgs.i_w, t_row * sets->imgs.i_h);
		sets->player.player_r = t_row;
		sets->player.player_c = t_col;
		ft_putnbr_fd(++sets->player.movement, 1);
		write(1, "\n", 1);
	}
	return (0);
}
