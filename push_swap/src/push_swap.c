/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:32:05 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/11 18:23:29 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_ps_stacks	*stacks;

	if (ac < 2)
		ps_exit();
	else
	{
		stacks = ps_init_stacks();
		if (!stacks)
			ps_exit();
		if (ps_input(ac, av, stacks) == -1)
			ps_exit();
		if (ps_sort(stacks) == -1)
		{
			ps_free_stacks(stacks);
			ps_exit();
		}
		ps_free_stacks(stacks);
	}
	return (0);
}
