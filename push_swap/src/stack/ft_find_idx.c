/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_idx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:04:10 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/12 17:07:23 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_find_idx(t_stack *stack, int element)
{
	int		idx;
	t_dlst	*tmp;

	idx = 0;
	tmp = stack->head;
	while (tmp)
	{
		if (tmp->element == element)
			return (idx);
		idx++;
		tmp = tmp->next;
	}
	return (idx);
}
