/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_make_env_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:02:32 by hocjeong          #+#    #+#             */
/*   Updated: 2024/11/14 20:14:14 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_environment.h"

static void	free_varname_value(char *varname, char *value)
{
	if (varname)
		free(varname);
	if (value)
		free(value);
	varname = NULL;
	value = NULL;
}

int	mn_make_env_lst(char **envp, t_env **env, char export_flag)
{
	t_env	*new;
	char	*varname;
	char	*value;

	while (*envp)
	{
		varname = mn_parse_varname(*envp, get_equal_idx(*envp), NULL);
		value = mn_parse_value(*envp, get_equal_idx(*envp));
		new = mn_new_env(varname, value);
		if (new == NULL)
		{
			mn_print_error(MALLOC, NULL);
			free_varname_value(varname, value);
			return (-1);
		}
		if (export_flag)
			mn_insert_exports(env, new);
		else
			mn_insert_envs(env, new);
		envp++;
		free_varname_value(varname, value);
	}
	return (0);
}
