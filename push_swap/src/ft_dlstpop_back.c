/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpop_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:10:17 by hocjeong          #+#    #+#             */
/*   Updated: 2024/06/13 21:24:57 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_dlstpop_back(t_stack *stack)
{
	t_dlst	*tmp;

	if (stack->tail == NULL)
		return (-1);
	tmp = stack->tail->prev;
	ft_dlstdel_one(stack->tail);
	if (tmp != NULL)
		tmp->next = NULL;
	stack->tail = tmp;
	stack->size--;
	return (0);
}
