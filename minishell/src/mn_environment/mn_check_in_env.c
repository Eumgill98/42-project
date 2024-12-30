/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_check_in_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:05:24 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/22 21:08:16 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_environment.h"

int	mn_check_in_env(t_env *envs, char *varname)
{
	t_env	*tmp;

	tmp = envs;
	while (tmp)
	{
		if (ft_strcmp(tmp->varname, varname) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
