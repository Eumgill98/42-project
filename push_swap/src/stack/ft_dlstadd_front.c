/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:26:56 by hocjeong          #+#    #+#             */
/*   Updated: 2024/06/19 17:00:06 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_dlstadd_front(t_stack *stack, int data)
{
	t_dlst	*tmp;

	tmp = ft_dlstnew(data);
	if (!tmp)
		return (-1);
	if (stack->head == NULL)
	{
		stack->head = tmp;
		stack->tail = tmp;
	}
	else
	{
		tmp->next = stack->head;
		stack->head->prev = tmp;
		stack->head = tmp;
	}
	stack->size++;
	return (0);
}
