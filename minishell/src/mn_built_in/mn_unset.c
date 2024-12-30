/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:30:07 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/27 15:16:42 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_built_in.h"

static void	pop_env_by_varname(t_env *head, char *varname)
{
	t_env	*tmp;

	if (!head || !varname)
		return ;
	tmp = head;
	while (tmp)
	{
		if (ft_strcmp(tmp->varname, varname) == 0)
		{
			if (tmp->prev)
				tmp->prev->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = tmp->prev;
			mn_destroy_env(tmp);
			free(tmp);
			return ;
		}
		tmp = tmp->next;
	}
}

int	mn_unset(t_environment *environment, t_arg *head)
{
	t_arg	*tmp;

	if (head == NULL)
		return (0);
	tmp = head;
	while (tmp)
	{
		pop_env_by_varname(environment->envs, tmp->arg);
		pop_env_by_varname(environment->exports, tmp->arg);
		tmp = tmp->next;
	}
	return (0);
}
