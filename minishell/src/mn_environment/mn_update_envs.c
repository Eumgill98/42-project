/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_update_envs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:56:23 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/22 21:29:17 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_environment.h"

void	mn_update_envs(t_env **envs, char **varname, char *value)
{
	t_env	*tmp;
	t_env	*new;
	int		plus;

	plus = mn_check_plus(varname);
	tmp = *envs;
	if (value == NULL && mn_check_in_env(tmp, *varname) == 1)
		return ;
	if (mn_check_in_env(tmp, *varname) == 1)
		mn_change_env_value(envs, *varname, value, plus);
	else
	{
		new = mn_new_env(*varname, value);
		if (new == NULL)
		{
			mn_print_error(MALLOC, NULL);
			return ;
		}
		mn_insert_envs(envs, new);
	}
}
