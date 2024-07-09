/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:32:05 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/09 16:09:05 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char		**inputs;
	t_ps_stacks	*stacks;

	if (ac < 2)
		ps_exit();
	else
	{
		inputs = ps_input(ac, av);
		if (!inputs)
			ps_exit();
		stacks = ps_init_stacks(inputs);
		if (ac == 2)
			ps_free_input(inputs);
		if (!stacks)
			ps_exit();
		//run
	}
	return (0);
}
