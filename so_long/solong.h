/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:46:40 by hocjeong          #+#    #+#             */
/*   Updated: 2024/05/14 19:11:43 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <libft.h>
# include "get_next_line/get_next_line.h"

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

int		check_maps(t_maps *maps);

#endif
