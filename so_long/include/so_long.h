/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:46:40 by hocjeong          #+#    #+#             */
/*   Updated: 2024/05/27 14:37:03 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <libft.h>
# include "get_next_line.h"

# define X_WINDOW 17
# define KEY_ESC 0xFF1B
# define KEY_W 119
# define KEY_A 100
# define KEY_S 115
# define KEY_D 97

typedef struct s_maps {
	int	e_num;
	int	p_num;
	int	c_num;
}	t_maps;

typedef struct s_play {
	int	player_r;
	int	player_c;
	int	collected;
	int	direction;
	int	door_r;
	int	door_c;
	int	door_open;
	int	movement;
}	t_play;

typedef struct s_imgs {
	void	*g;
	void	*w;
	void	*c;
	void	*e;
	void	*e_open;
	void	*back;
	void	*right;
	void	*front;
	void	*left;
	int		i_w;
	int		i_h;
}	t_imgs;

typedef struct s_sets {
	void	*mlx_ptr;
	void	*win_ptr;
	t_maps	map_flag;
	t_play	player;
	t_imgs	imgs;
	int		w_w;
	int		w_h;
	t_list	*map_lst;
	char	**map;
	char	**visited;	
	int		fd;
	int		row;
	int		col;

}	t_sets;

void	error_exit(t_sets *sets);
void	freemap_lst(t_sets *sets);
void	freemap(t_sets *sets, int idx);
void	freevis(t_sets *sets, int idx);
void	freemap_flag(t_sets *sets);
void	freeimg(t_sets *sets, void *img);
void	all_freeimg(t_sets *sets);

int		init_sets(t_sets *sets, char *map_path);

int		load_map(t_sets *sets);

int		check_rectangular(t_sets *sets);
int		check_component(t_sets *sets);
int		check_wall(t_sets *sets);
int		check_path(t_sets *sets);
int		map_check(t_sets *sets);

int		player_draw(t_sets *sets, int x, int y);
int		img_draw(t_sets *sets, char flag, int x, int y);
int		map_draw(t_sets *sets);

int		key_hook(int keycode, t_sets *sets);
int		clear_game(t_sets *sets);
#endif
