/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:42:28 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/15 15:03:50 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_two_sort(t_ps_stacks *stacks)
{
	t_dlst	*tmp;

	tmp = stacks->stack_a->head;
	if (tmp->element > tmp->next->element)
		ps_functions(stacks, "sa", 1);
	return (0);
}

static int	ps_three_sort(t_ps_stacks *stacks)
{
	if (ps_check_case(stacks->stack_a->head) == 0)
	{
		ps_functions(stacks, "sa", 1);
		ps_functions(stacks, "ra", 1);
	}
	else if (ps_check_case(stacks->stack_a->head) == 1)
		ps_functions(stacks, "rra", 1);
	else if (ps_check_case(stacks->stack_a->head) == 2)
		ps_functions(stacks, "sa", 1);
	else if (ps_check_case(stacks->stack_a->head) == 3)
	{
		ps_functions(stacks, "sa", 1);
		ps_functions(stacks, "rra", 1);
	}
	else if (ps_check_case(stacks->stack_a->head) == 4)
		ps_functions(stacks, "ra", 1);
	return (0);
}

static int	ps_four_sort(t_ps_stacks *stacks)
{
	int	min_idx;

	min_idx = ps_min_idx(stacks);
	ps_pb_idx(stacks, min_idx, 4);
	ps_three_sort(stacks);
	ps_functions(stacks, "pa", 1);
	return (0);
}

static int	ps_five_sort(t_ps_stacks *stacks)
{
	int	min_idx;
	int	max_idx;

	min_idx = ps_min_idx(stacks);
	ps_pb_idx(stacks, min_idx, 5);
	max_idx = ps_max_idx(stacks);
	ps_pb_idx(stacks, max_idx, 4);
	ps_three_sort(stacks);
	ps_functions(stacks, "pa", 1);
	return (0);
}

void	ps_sort_small(t_ps_stacks *stacks)
{
	int	total_size;

	total_size = stacks->stacks_a->size;
	if (total_size == 2)
		ps_two_sort(stacks);
	else if (total_size == 3)
		ps_three_sort(stacks);
	else if (total_size == 4)
		ps_four_sort(stacks);
	else
		ps_five_sort(stacks);
}
