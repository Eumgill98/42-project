/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_update_exports.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:23:47 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/08 17:32:37 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_environment.h"

void	mn_update_exports(t_env **exports, char **varname, char *value)
{
	t_env	*tmp;
	t_env	*new;
	int		plus;

	plus = mn_check_plus(varname);
	tmp = *exports;
	if (value == NULL && mn_check_in_env(tmp, *varname) == 1)
		return ;
	if (mn_check_in_env(tmp, *varname) == 1)
		(mn_change_env_value(exports, *varname, value, plus));
	else
	{
		new = mn_new_env(*varname, value);
		if (new == NULL)
		{
			mn_print_error(MALLOC, NULL);
			return ;
		}
		mn_insert_exports(exports, new);
	}
}
