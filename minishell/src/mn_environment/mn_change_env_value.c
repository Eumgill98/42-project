/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_change_env_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:14:28 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/22 21:27:35 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_environment.h"

static char	*str_return(char *tmp_value, char *value, int plus)
{
	if (plus)
	{
		if (tmp_value && tmp_value[0] != '\0')
			return (ft_strjoin(tmp_value, value));
	}
	return (ft_strdup(value));
}

void	mn_change_env_value(t_env **exports, char *varname, \
		char *value, int plus)
{
	t_env	*tmp;
	char	*tmp_str;

	tmp = *exports;
	while (tmp)
	{
		if (ft_strcmp(tmp->varname, varname) == 0)
		{
			tmp_str = str_return(tmp->value, value, plus);
			if (tmp_str == NULL)
				mn_print_error(MALLOC, NULL);
			if (tmp->value)
				free(tmp->value);
			tmp->value = tmp_str;
			return ;
		}
		tmp = tmp->next;
	}
}
