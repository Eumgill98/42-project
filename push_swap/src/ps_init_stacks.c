/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:57:46 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/11 17:58:40 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_stacks	*ps_init_stacks(void)
{
	t_ps_stacks	*tmp;

	tmp = (t_ps_stacks *)malloc(sizeof(t_ps_stacks));
	if (!tmp)
		return (NULL);
	tmp->stack_a = ft_stackinit();
	tmp->stack_b = ft_stackinit();
	if (!tmp->stack_b)
	{
		ps_free_stacks(tmp);
		return (NULL);
	}
	return (tmp);
}
