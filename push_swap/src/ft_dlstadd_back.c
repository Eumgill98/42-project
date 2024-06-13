/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:08:44 by hocjeong          #+#    #+#             */
/*   Updated: 2024/06/13 20:36:08 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_dlstadd_back(t_stack *stack, char data)
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
		tmp->prev = tail;
		stack->tail->next = tmp;
		stack->tail = tmp;
	}
	stack->size++;
	return (0);
}
