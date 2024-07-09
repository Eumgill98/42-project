/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:57:41 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/09 17:05:03 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_sort_check(t_stack *stack)
{
	t_dlst	*tmp;
	int		now;

	if (!stack || !stack->head)
		return (-1);
	tmp = stack->head;
	now = tmp->element;
	tmp = tmp->next;
	while (tmp)
	{
		if (now >= tmp->element)
			return (-1);
		now = tmp->element;
		tmp = tmp->next;
	}
	return (0);
}

int	ps_rsort_check(t_stack *stack)
{
	t_dlst	*tmp;
	int		now;

	if (!stack || !stack->tail)
		return (-1);
	tmp = stack->tail;
	now = tmp->element;
	tmp = tmp->prev;
	while (tmp)
	{
		if (now >= tmp->element)
			return (-1);
		now = tmp->element;
		tmp = tmp->prev;
	}
	return (0);
}
