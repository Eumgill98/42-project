/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:13:03 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/11 16:40:14 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_input(int ac, char **av, t_ps_stacks *stacks)
{
	char	**s;
	int		idx;

	idx = 1;
	while (idx < ac)
	{
		s = ft_split(av[idx], ' ');
		if (check_overflow(s) == -1 || \
			check_form(s) == -1 || \
			ft_stackappend(stacks->stack_a, s) == -1)
		{
			ps_free_input(s);
			ps_free_stacks(stacks);
			return (-1);
		}
		ps_free_input(s);
		idx++;
	}
	if (check_dup(stacks->stack_a) == -1)
	{
		ps_free_stacks(stacks);
		return (-1);
	}
	return (0);
}
