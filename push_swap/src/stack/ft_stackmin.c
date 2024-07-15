/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackmin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:02:08 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/12 17:04:34 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_stackmin(t_stack *stack)
{
	int		min;
	t_dlst	*tmp;

	tmp = stack->head;
	min = tmp->element;
	while (tmp)
	{
		if (tmp->element < min)
			min = tmp->element;
		tmp = tmp->next;
	}
	return (min);
}
