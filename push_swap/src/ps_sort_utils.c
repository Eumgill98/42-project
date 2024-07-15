/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:11:39 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/15 15:03:17 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_check_case(t_dlst *head)
{
	int	f_e;
	int	s_e;
	int	t_e;

	f_e = head->element;
	s_e = head->next->element;
	t_e = head->next->next->element;
	if (f_e < s_e && s_e > t_e && f_e < t_e)
		return (0);
	else if (f_e < s_e && s_e > t_e && f_e > t_e)
		return (1);
	else if (f_e > s_e && s_e < t_e && f_e < t_e)
		return (2);
	else if (f_e > s_e && s_e > t_e && f_e > t_e)
		return (3);
	else if (f_e > s_e && s_e < t_e && f_e > t_e)
		return (4);
	return (-1);
}

int	ps_max_idx(t_ps_stacks *stacks)
{
	int	max_idx;
	int	max_e;

	max_e = ft_stackmax(stacks->stack_a);
	max_idx = ft_find_idx(stacks->stack_a, max_e);
	return (max_idx);
}

int	ps_min_idx(t_ps_stacks *stacks)
{
	int	min_idx;
	int	min_e;

	min_e = ft_stackmin(stacks->stack_a);
	min_idx = ft_find_idx(stacks->stack_a, min_e);
	return (min_idx);
}

int	ps_pb_idx(t_ps_stacks *stacks, int idx, int size)
{
	if (idx == 1)
		ps_functions(stacks, "ra", 1);
	else if (idx == 2)
	{
		ps_functions(stacks, "ra", 1);
		ps_functions(stacks, "ra", 1);
	}
	else if (idx == 3)
	{
		if (size == 4)
			ps_functions(stacks, "rra", 1);
		else if (size == 5)
		{
			ps_functions(stacks, "rra", 1);
			ps_functions(stacks, "rra", 1);
		}
	}
	ps_functions(stacks, "pb", 1);
	return (0);
}
