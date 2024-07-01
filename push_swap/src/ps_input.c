/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:37:03 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/01 16:21:53 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ps_input(int ac, char **av)
{
	char	**tmp;

	tmp = &av[1];
	if (ac == 2)
		tmp = ft_split(tmp[0]);
	if (!tmp)
		return (NULL);
	if (check_form == -1 || check_overflow == -1 || check_dup == -1)
		return (NULL);
	return (tmp);
}
