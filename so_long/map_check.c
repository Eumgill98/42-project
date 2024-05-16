/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:47:57 by hocjeong          #+#    #+#             */
/*   Updated: 2024/05/16 18:36:21 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	map_check(t_sets *sets)
{
	if (check_rectangular(sets) == -1)
		return (-1);
	if (check_component(sets) == -1)
		return (-1);
	if (check_wall(sets) == -1)
		return (-1);
	//todo path check
	return (0)
}
