/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:37:03 by hocjeong          #+#    #+#             */
/*   Updated: 2024/06/17 17:10:32 by hocjeong         ###   ########.fr       */
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
		j = i + 1;
		while (s[j])
		{
			if (ft_atoi(s[i]) == ft_atoi(s[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (len);
}
