/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:57:46 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/11 17:42:57 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_swap(t_ps_stacks *stacks, int c_idx)
{
	if (c_idx == 29)
		return (ft_swap(stacks->stack_a));
	else if (c_idx == 30)
		return (ft_swap(stacks->stack_b));
	else if (c_idx == 5)
	{
		if (!ft_swap(stacks->stack_a) && !ft_swap(stacks->stack_b))
			return (0);
		else
			return (-1);
	}
	return (-1);
}

int	ps_push(t_ps_stacks *stacks, int c_idx)
{
	if (c_idx == 41)
		return (ft_push(stacks->stack_b, stacks->stack_a));
	else if (c_idx == 0)
		return (ft_push(stacks->stack_a, stacks->stack_b));
	return (-1);
}

int	ps_rotate(t_ps_stacks *stacks, int c_idx)
{
	if (c_idx == 19)
		return (ft_rotate(stacks->stack_a));
	else if (c_idx == 20)
		return (ft_rotate(stacks->stack_b));
	else if (c_idx == 36)
	{
		if (!ft_rotate(stacks->stack_a) && !ft_rotate(stacks->stack_b))
			return (0);
		else
			return (-1);
	}
	return (-1);
}

int	ps_rrotate(t_ps_stacks *stacks, int c_idx)
{
	if (c_idx == 37)
		return (ft_rrotate(stacks->stack_a));
	else if (c_idx == 38)
		return (ft_rrotate(stacks->stack_b));
	else if (c_idx == 12)
	{
		if (!ft_rrotate(stacks->stack_a) && !ft_rrotate(stacks->stack_b))
			return (0);
		else
			return (-1);
	}
	return (-1);
}

int	ps_functions(t_ps_stacks *stacks, const char *command, int flag)
{
	int	c_idx;

	if (flag)
		ps_printstr(command);
	c_idx = ps_encoding(command);
	if (c_idx == 29 || c_idx == 30 || c_idx == 5)
		return (ps_swap(stacks, c_idx));
	else if (c_idx == 41 || c_idx == 0)
		return (ps_push(stacks, c_idx));
	else if (c_idx == 19 || c_idx == 20 || c_idx == 36)
		return (ps_rotate(stacks, c_idx));
	else if (c_idx == 37 || c_idx == 38 || c_idx == 12)
		return (ps_rrotate(stacks, c_idx));
	return (-1);
}
