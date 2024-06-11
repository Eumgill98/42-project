/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:58:27 by hocjeong          #+#    #+#             */
/*   Updated: 2024/06/11 20:09:59 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int	size_stack(char	**s)
{
	int	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

void	make_stack(t_stack *stack, char	**s)
{
	// s 배열 길이 만큼돌면서 이중 연결 리스트 값 생성
	int	idx;
	t_dlst	*curr;

	stack->size = size_stack(s);
}
