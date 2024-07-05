/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:57:46 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/04 17:36:45 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  str_to_num(char *command)
{
    int idx;
    int num;

    idx = 0;
    num = 0;
    while (command[idx])
    {
        num += ((10 ** idx) * command[idx]);
        idx++;
    }
    return (num % 42);
}

int ps_functions(t_ps_stack *stacks, char *command)
{

}