/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:07:33 by hocjeong          #+#    #+#             */
/*   Updated: 2024/05/22 17:57:47 by hocjeong         ###   ########.fr       */
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

void	freevis(t_sets *sets, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		free(sets->visited[i]);
		sets->visited[i] = 0;
		i++;
	}
	free(sets->visited);
	sets->visited = 0;
}

void	freeimg(t_sets *sets, void *img)
{
	mlx_destroy_image(sets->mlx_ptr, img);
	img = NULL;
}

void	all_freeimg(t_sets *sets)
{
	if (sets->imgs.g)
		freeimg(sets, sets->imgs.g);
	if (sets->imgs.w)
		freeimg(sets, sets->imgs.w);
	if (sets->imgs.c)
		freeimg(sets, sets->imgs.c);
	if (sets->imgs.e)
		freeimg(sets, sets->imgs.e);
	if (sets->imgs.e_open)
		freeimg(sets, sets->imgs.e_open);
	if (sets->imgs.back)
		freeimg(sets, sets->imgs.back);
	if (sets->imgs.front)
		freeimg(sets, sets->imgs.front);
	if (sets->imgs.right)
		freeimg(sets, sets->imgs.right);
	if (sets->imgs.left)
		freeimg(sets, sets->imgs.left);
}
