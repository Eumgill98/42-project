/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:30:05 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/11 18:37:05 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_bsize(int nbr)
{
	int	size;

	size = 0;
	while (nbr)
	{
		nbr /= 2;
		size++;
	}
	return (size);
}

static int	ps_check(t_ps_stacks *stacks, int idx)
{
	int		len;
	t_dlst	*tmp;

	len = stacks->stack_a->size;
	while (len--)
	{
		tmp = stacks->stack_a->head;
		if ((tmp->element >> idx) & 1)
			ps_functions(stacks, "ra", 1);
		else
			ps_functions(stacks, "pb", 1);
	}
	return (0);
}

static int	ps_merge(t_ps_stacks *stacks)
{
	int	len;

	len = stacks->stack_b->size;
	while (len--)
		ps_functions(stacks, "pa", 1);
	return (0);
}

void	ps_sort_big(t_ps_stacks *stacks)
{
	int	total_size;
	int	idx;

	total_size = ft_bsize(stacks->stack_a->size - 1);
	idx = 0;
	while (idx < total_size)
	{
		ps_check(stacks, idx);
		ps_merge(stacks);
		idx++;
	}
}
