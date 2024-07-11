/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:43:06 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/11 17:47:37 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_printstr(const char *s)
{
	int	idx;

	idx = 0;
	while (s[idx])
	{
		write(1, &s[idx], 1);
		idx++;
	}
	write(1, "\n", 1);
}
