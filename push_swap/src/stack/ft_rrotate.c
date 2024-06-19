/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:40:30 by hocjeong          #+#    #+#             */
/*   Updated: 2024/06/19 17:42:48 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_rrotate(t_stack *stack)
{
	int	tmp;

	if (!stack || !stack->head || stack->size <= 1)
		return (-1);
	tmp = stack->tail->element;
	ft_dlstpop_back(stack);
	ft_dlstadd_front(stack, tmp);
	return (0);
}
