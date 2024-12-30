/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_destroy_env_lst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:29:27 by hocjeong          #+#    #+#             */
/*   Updated: 2024/11/27 20:36:17 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_environment.h"

void	mn_destroy_env_lst(t_env *head)
{
	t_env	*tmp_next;

	while (head)
	{
		tmp_next = head->next;
		mn_destroy_env(head);
		free(head);
		head = tmp_next;
	}
}
