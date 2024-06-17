/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpop_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:20:28 by hocjeong          #+#    #+#             */
/*   Updated: 2024/06/17 15:44:57 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"

void	ft_dlstpop_all(t_stack *stack)
{
	int	flag;

	if (!stack)
		return ;
	flag = ft_dlstpop_front(stack);
	while (flag != -1)
		flag = ft_dlstpop_front(stack);
}
