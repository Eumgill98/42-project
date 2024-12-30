/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_insert_envs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:02:45 by hocjeong          #+#    #+#             */
/*   Updated: 2024/11/14 19:20:43 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_environment.h"

void	mn_insert_envs(t_env **envs, t_env *new)
{
	t_env	*tmp;

	tmp = *envs;
	if (tmp == NULL)
	{
		insert_at_head(envs, new);
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	insert_at_tail(tmp, new);
}
