/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:57:28 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/11 15:36:34 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_dlstswap(t_dlst *node_a, t_dlst *node_b)
{
	int	tmp;

	if (!node_a || !node_b)
		return (-1);
	tmp = node_a->element;
	node_a->element = node_b->element;
	node_b->element = tmp;
	return (0);
}
