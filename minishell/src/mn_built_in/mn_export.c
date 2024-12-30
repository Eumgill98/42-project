/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:52:02 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/22 20:13:49 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_built_in.h"

static void	free_varname_value(char *varname, char *value)
{
	if (varname)
		free(varname);
	if (varname)
		free(value);
	varname = NULL;
	value = NULL;
}

static int	error_check(char *varname, char *value, int flag)
{
	if (varname == NULL && flag == 0)
	{
		mn_print_error(MALLOC, NULL);
		free_varname_value(varname, value);
		return (1);
	}
	else if (varname == NULL || flag == 1)
	{
		free_varname_value(varname, value);
		return (1);
	}
	return (0);
}

static int	mn_export_add_args(t_environment *environment, t_arg *head)
{
	t_arg	*tmp;
	int		flag;
	char	*varname;
	char	*value;

	tmp = head;
	flag = 0;
	while (tmp)
	{
		varname = mn_parse_varname(tmp->arg, get_equal_idx(tmp->arg), &flag);
		value = mn_parse_value(tmp->arg, get_equal_idx(tmp->arg));
		flag = error_check(varname, value, flag);
		if (flag)
			return (flag);
		if (value == NULL)
			mn_update_exports(&(environment->exports), &varname, value);
		else
		{
			mn_update_envs(&(environment->envs), &varname, value);
			mn_update_exports(&(environment->exports), &varname, value);
		}
		free_varname_value(varname, value);
		tmp = tmp->next;
	}
	return (0);
}

int	mn_export(t_environment *environment, t_arg *head)
{
	if (head == NULL)
		mn_print_env_lst(environment->exports, 1);
	else
		return (mn_export_add_args(environment, head));
	return (0);
}
