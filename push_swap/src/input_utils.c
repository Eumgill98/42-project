/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:37:03 by hocjeong          #+#    #+#             */
/*   Updated: 2024/06/18 13:51:17 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_dstrlen(char **s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

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

int	check_input(char **s)
{
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s || !(*s))
		return (-1);
	len = ft_dstrlen(s);
	i = 0;
	while (i < len)
	{
		if (check_wrong_form(s[j]) == -1)
			return (-1);
		j = i + 1;
		while (s[j])
		{
			if (check_duplication(s[i], s[j]) == -1 \
				|| check_wrong_form(s[j]) == -1)
				return (-1);
			j++;
		}
		i++;
	}
	return (len);
}
