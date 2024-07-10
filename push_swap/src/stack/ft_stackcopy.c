/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackcopy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:14:13 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/04 17:19:00 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack *ft_stackcopy(t_stack *origin_stack)
{
    t_stack *new_stack;
    t_dlst  *tmp;

    new_stack = ft_stackinit();
    if (!new_stack)
        return (NULL);
    tmp = origin_stack->head;
    while(tmp)
    {
        if (ft_dlstadd_back(new_stack, tmp->element) == -1)
        {
            ft_dlstpop_all(new_stack);
            return(NULL);
        }
        tmp = tmp->next;
    }
    return (new_stack);
}