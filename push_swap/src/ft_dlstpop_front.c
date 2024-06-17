/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpop_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:01:58 by hocjeong          #+#    #+#             */
/*   Updated: 2024/06/17 16:19:40 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_dlstpop_front(t_stack *stack)
{
	t_dlst	*tmp;

	if (stack->head == NULL)
		return (-1);
	tmp = stack->head->next;
	ft_dlstdel_one(stack->head);
	if (tmp != NULL)
		tmp->prev = NULL;
	else
		stack->tail = NULL;
	stack->head = tmp;
	stack->size--;
	return (0);
}
