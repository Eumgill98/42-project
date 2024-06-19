/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackmake.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:58:27 by hocjeong          #+#    #+#             */
/*   Updated: 2024/06/19 16:59:28 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_stackmake(t_stack *stack, char **s)
{
	int	idx;

	if (!s || !stack)
		return (-1);
	idx = 0;
	while (s[idx])
	{
		if (ft_dlstadd_back(stack, ft_atoi(s[idx])) == -1)
		{
			ft_dlstpop_all(stack);
			return (-1);
		}
		idx++;
	}
	return (0);
}
