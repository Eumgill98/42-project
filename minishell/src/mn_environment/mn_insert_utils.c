/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_insert_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:42:39 by hocjeong          #+#    #+#             */
/*   Updated: 2024/11/27 20:23:22 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_environment.h"

void	insert_at_head(t_env **head, t_env *new)
{
	if (*head)
	{
		new->next = (*head);
		(*head)->prev = new;
	}
	*head = new;
}

void	insert_at_tail(t_env *tail, t_env *new)
{
	tail->next = new;
	new->prev = tail;
}
