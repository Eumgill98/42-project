/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_make_idx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:57:28 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/09 16:57:33 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void bubble_sort(t_stack *stack)
{
    t_dlst  *tmp;
    t_dlst  *break_point;

    break_point = stack->tail;
    while (stack->head != break_point)
    {
        tmp = stack->head;
        while (tmp != break_point)
        {
            if (tmp->element > tmp->next->element)
                ft_dlstswap(tmp, tmp->next);
            tmp = tmp->next;
        }
        break_point = break_point->prev;
    }
}

static int  insert_idx(t_stack *origin, t_stack *copy)
{
    t_dlst  *tmp;
    t_dlst  *n_tmp;
    int idx;

    tmp = origin->head;
    while (tmp)
    {
        n_tmp = copy->head;
        idx = 0;
        while (n_tmp)
        {
            if (n_tmp->element == tmp->element)
            {
                tmp->idx = idx;
                break;
            }
            idx++;
            n_tmp = n_tmp->next;
        }
        tmp = tmp->next;
    }
    return (0);
}

int ps_make_idx(t_stack *stack)
{
    t_stack *new_stack;

    new_stack = ft_stackcopy(stack);
    if (!new_stack)
        return (-1);
    bubble_sort(new_stack);
    insert_idx(stack, new_stack);
    ft_stackfree(new_stack);
    return (0);
}