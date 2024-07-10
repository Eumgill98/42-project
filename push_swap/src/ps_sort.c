/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:57:28 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/09 16:57:33 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ps_sort(t_stack *stack)
{
    if (ps_sort_check(stack))
        return (0);
    if (stack->size <= 5)
        // sort_small()
    else
        // sort_big() -> in ps_make_idx use make idx;
    return (0);
}