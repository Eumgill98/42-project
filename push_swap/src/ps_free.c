/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:37:33 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/04 17:22:30 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_free_stacks(t_ps_stacks *stacks)
{
	if (stacks->stack_a)
		ft_stackfree(stacks->stack_a);
	if (stacks->stack_b)
		ft_stackfree(stacks->stack_b);
	free(stacks);
}

void	ps_free_input(char **s)
{
	int	idx;

	idx = 0;
	while (s[idx])
	{
		free(s[idx]);
		s[idx] = NULL;
		idx++;
	}
	free(s);
}
