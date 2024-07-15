/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackmax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:57:37 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/15 15:57:59 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_stackmax(t_stack *stack)
{
	int		max;
	t_dlst	*tmp;

	tmp = stack->head;
	max = tmp->element;
	while (tmp)
	{
		if (tmp->element > max)
			max = tmp->element;
		tmp = tmp->next;
	}
	return (max);
}
