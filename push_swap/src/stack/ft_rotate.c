/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:36:56 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/04 18:04:25 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_rotate(t_stack *stack)
{
	int	tmp;

	if (!stack || !stack->head || stack->size <= 1)
		return (-1);
	tmp = stack->head->element;
	ft_dlstpop_front(stack);
	ft_dlstadd_back(stack, tmp);
	return (0);
}
