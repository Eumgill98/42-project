/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_destroy_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:51:10 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/12 19:52:24 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

void	mn_destroy_process(t_process *head)
{
	t_process	*tmp;
	t_process	*next;

	tmp = head;
	while (tmp)
	{
		next = tmp->next;
		mn_del_process(tmp);
		free(tmp);
		tmp = next;
	}
}
