/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:37:03 by hocjeong          #+#    #+#             */
/*   Updated: 2024/06/26 20:08:40 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_input(int ac, char **av)
{
	char	**tmp;
	// input의 형태가 2개임
	// ./push_swap 2 1 3 6 5 8 
	// ./push_swap "4 67 3 87 23" 
	
	tmp = &av[1];
	if (ac == 2)
		tmp = ft_split(tmp[0]);
	
}
