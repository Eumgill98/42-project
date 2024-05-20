/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:46:40 by hocjeong          #+#    #+#             */
/*   Updated: 2024/05/20 17:55:05 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <libft.h>
# include "get_next_line.h"

typedef struct s_maps {
	int	e_num;
	int	p_num;
	int	c_num;
}	t_maps;

typedef struct s_sets {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*g;
	void	*w;
	void	*c;
	void	*e;
	void	*p;
	int		i_w;
	int		i_h;
	int		w_w;
	int		w_h;
	t_list	*map_lst;
	char	**map;
	char	**visited;	
	int		fd;
	int		row;
	int		col;
	int		player_r;
	int		player_c;
	t_maps	map_flag;
}	t_sets;

void	freemap_lst(t_sets *sets);
void	freemap(t_sets *sets, int idx);
void	freevis(t_sets *sets, int idx);
void	freemap_flag(t_sets *sets);
int		esc_hook(int keycode, t_sets *sets);

int		init_sets(t_sets *sets, char *map_path);

int		load_map(t_sets *sets);

int		check_rectangular(t_sets *sets);
int		check_component(t_sets *sets);
int		check_wall(t_sets *sets);
int		check_path(t_sets *sets);
int		map_check(t_sets *sets);

int		map_draw(t_sets *sets);

void	error_exit(t_sets *sets);
#endif
