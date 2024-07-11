/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_input_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:05:47 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/11 16:32:01 by hocjeong         ###   ########.fr       */
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

int	check_dup(t_stack *stack)
{
	t_dlst	*tmp;
	t_dlst	*tmp_n;

	tmp = stack->head;
	while (tmp)
	{
		tmp_n = tmp->next;
		while (tmp_n)
		{
			if (tmp->element == tmp_n->element)
				return (-1);
			tmp_n = tmp_n->next;
		}
		tmp = tmp->next;
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
