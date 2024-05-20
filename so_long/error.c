/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:33:32 by hocjeong          #+#    #+#             */
/*   Updated: 2024/05/20 17:44:54 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(t_sets *sets)
{
	write(1, "Error\n", 6);
	mlx_destroy_display(sets->mlx_ptr);
	free(sets->mlx_ptr);
	freemap(sets, sets->row);
	if (sets->visited)
	freevis(sets, sets->row);
	close(sets->fd);
	exit(0);
}
