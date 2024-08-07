/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:44:30 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/11 17:20:52 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"

int	ft_push(t_stack *on_stack, t_stack *to_stack)
{
	int	tmp;

	if (!on_stack || !to_stack || on_stack->size == 0)
		return (-1);
	tmp = on_stack->head->element;
	ft_dlstpop_front(on_stack);
	ft_dlstadd_front(to_stack, tmp);
	return (0);
}
