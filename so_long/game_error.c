/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:33:32 by hocjeong          #+#    #+#             */
/*   Updated: 2024/05/27 14:35:52 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	freemlx(t_sets *sets)
{
	mlx_destroy_display(sets->mlx_ptr);
	free(sets->mlx_ptr);
	sets->mlx_ptr = NULL;
}

static void	freewin(t_sets *sets)
{
	mlx_destroy_window(sets->mlx_ptr, sets->win_ptr);
	free(sets->win_ptr);
	sets->win_ptr = NULL;
}

void	error_exit(t_sets *sets)
{
	write(1, "Error\n", 6);
	if (sets->fd >= 0)
		close(sets->fd);
	else
		exit(0);
	all_freeimg(sets);
	if (sets->win_ptr)
		freewin(sets);
	if (sets->mlx_ptr)
		freemlx(sets);
	if (sets->map)
		freemap(sets, sets->row);
	if (sets->visited)
		freevis(sets, sets->row);
	exit(0);
}
