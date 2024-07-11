/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:57:28 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/11 18:25:48 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_sort(t_ps_stacks *stacks)
{
	if (!ps_sort_check(stacks->stack_a))
		return (0);
	if (ps_make_idx(stacks->stack_a) == -1)
		return (-1);
	ps_sort_big(stacks);
	return (0);
}
