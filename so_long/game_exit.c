/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:07:33 by hocjeong          #+#    #+#             */
/*   Updated: 2024/05/16 18:25:00 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freemap_lst(t_sets *sets)
{
	t_list	*curr;
	t_list	*next;

	curr = sets->map_lst;
	while (curr)
	{
		next = curr->next;
		free(curr->content);
		free(curr);
		curr = next;
	}
	free(curr);
}

void	freemap(t_sets *sets, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		free(sets->map[i]);
		sets->map[i] = 0;
		i++;
	}
	free(sets->map);
	sets->map = 0;
}

void	freemap_flag(t_sets *sets)
{
	free(sets->map_flag);
	sets->map_flag = 0;
}

int	esc_hook(int keycode, t_sets *sets)
{
	if (keycode == 0xFF1B)
	{
		mlx_destroy_window(sets->mlx_ptr, sets->win_ptr);
		mlx_destroy_display(sets->mlx_ptr);
		free(sets->mlx_ptr);
		freemap(sets, sets->row);
		close(sets->fd);
		exit(0);
	}
	return (0);
}
