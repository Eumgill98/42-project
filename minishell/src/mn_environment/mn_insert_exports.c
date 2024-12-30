/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_insert_exports.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:02:30 by hocjeong          #+#    #+#             */
/*   Updated: 2024/11/27 20:38:42 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_environment.h"

void	mn_insert_exports(t_env **exports, t_env *new)
{
	t_env	*tmp;
	t_env	*prev;

	if (new->varname[0] == '_')
	{
		mn_destroy_env(new);
		free(new);
		return ;
	}
	tmp = *exports;
	prev = NULL;
	while (tmp && ft_strcmp(tmp->varname, new->varname) <= 0)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	new->prev = prev;
	new->next = tmp;
	if (prev)
		prev->next = new;
	else
		*exports = new;
	if (tmp)
		tmp->prev = new;
}
