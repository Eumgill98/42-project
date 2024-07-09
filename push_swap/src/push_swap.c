/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:32:05 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/09 15:45:52 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char		**inputs;
	t_ps_stacks	*stacks;

	if (ac < 2)
		return (0);
	else
	{
		inputs = ps_input(ac, av);
		if (!inputs)
			return (0);
		stacks = ps_init_stacks(inputs);
		if (ac == 2)
			ps_free_inputs(inputs);
		if (!stacks)
			return (0);
	}
	return (0);
}
