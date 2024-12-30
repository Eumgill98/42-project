/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_destroy_token_lst.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:04:31 by hocjeong          #+#    #+#             */
/*   Updated: 2024/11/12 21:10:31 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

void	mn_destroy_token_lst(t_token *head)
{
	t_token	*tmp;

	while (head)
	{
		tmp = head;
		free(tmp->content);
		tmp->content = NULL;
		head = head->next;
		free(tmp);
	}
}
