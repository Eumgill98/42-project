/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_input_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:05:47 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/04 17:52:21 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_overflow(char **s)
{
	int	overflow;
	int	idx;

	overflow = 0;
	idx = 0;
	while (s[idx])
	{
		ft_atoil(s[idx], &overflow);
		if (overflow)
			return (-1);
		idx++;
	}
	return (0);
}

int	check_dup(char **s)
{
	int	i;
	int	j;
	int	now;

	i = 0;
	while (s[i])
	{
		j = i + 1;
		now = ft_atoi(s[i]);
		while (s[j])
		{
			if (now == ft_atoi(s[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_form(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		if (s[i][j] == '-' || s[i][j] == '+')
			j++;
		if (!s[i][j])
			return (-1);
		while (s[i][j])
		{
			if (!(s[i][j] >= '0' || s[i][j] <= '9'))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
