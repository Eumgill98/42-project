/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:37:03 by hocjeong          #+#    #+#             */
/*   Updated: 2024/06/25 16:22:23 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_duplication(char *s1, char *s2)
{
	if (ft_atoi(s1) == ft_atoi(s2))
		return (-1);
	return (0);
}

static int	check_wrong_form(char *s)
{
	int	idx;

	idx = 0;
	while (s[idx])
	{
		if (!((*s >= '0' && *s <= '9') \
			|| *s == '+' || *s == '-'))
			return (-1);
		idx++;
	}
	return (0);
}

int	ps_input(char **s, int len)
{
	// 부호 
}
