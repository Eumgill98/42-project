/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:29:31 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/11 17:24:19 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_swap(t_stack	*stack)
{
	int	tmp;

	if (!stack || stack->size <= 1 || !stack->head)
		return (-1);
	tmp = stack->head->next->element;
	stack->head->next->element = stack->head->element;
	stack->head->element = tmp;
	return (0);
}
