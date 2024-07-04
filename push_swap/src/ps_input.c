/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:37:03 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/04 17:54:21 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ps_input(int ac, char **av)
{
	char	**tmp;

	tmp = &av[1];
	if (ac == 2)
		tmp = ft_split(tmp[0], ' ');
	if (!tmp)
		return (NULL);
	if (check_form(tmp) == -1 || \
		check_overflow(tmp) == -1 || \
			check_dup(tmp) == -1)
	{
		ps_free_input(tmp);
		return (NULL);
	}
	return (tmp);
}
