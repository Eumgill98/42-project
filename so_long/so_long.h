/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:46:40 by hocjeong          #+#    #+#             */
/*   Updated: 2024/05/14 21:42:37 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <libft.h>
# include "get_next_line.h"

typedef struct s_sets {
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_width;
	int		win_height;
}	t_sets;

typedef struct s_maps {
	t_list	*map_lst;
	char	**map;
	int		fd;
	int		row;
}	t_maps;

void	freemap_lst(t_maps *maps);
void	freemap(t_maps *maps, int idx);

void	set_maps(t_maps *maps, char *map_path);

int	load_map(t_maps *maps);
//int		check_maps(t_maps *maps);

#endif
