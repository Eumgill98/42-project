/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpop_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:01:58 by hocjeong          #+#    #+#             */
/*   Updated: 2024/06/13 21:23:55 by hocjeong         ###   ########.fr       */
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
	stack->head = tmp;
	stack->size--;
	return (0);
}
