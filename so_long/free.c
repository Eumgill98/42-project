/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:07:33 by hocjeong          #+#    #+#             */
/*   Updated: 2024/05/14 19:11:39 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freemap_lst(t_maps *maps)
{
	t_list	*curr;
	t_list	*next;

	curr = maps->map_lst;
	while (curr)
	{
		next = curr->next;
		free(curr->content);
		free(curr);
		curr = next;
	}
	free(curr);
}
	
void	freemap(t_maps *maps, int idx)
{
}
