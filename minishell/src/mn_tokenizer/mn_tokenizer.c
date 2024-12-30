/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:06:13 by hocjeong          #+#    #+#             */
/*   Updated: 2024/11/27 21:18:00 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

void	mn_remove_sp_token(t_token **head)
{
	t_token	*tmp;
	t_token	*next;

	while (*head && (*head)->token_type == SP)
	{
		next = (*head)->next;
		free((*head)->content);
		free((*head));
		*head = next;
		if (*head)
			(*head)->prev = NULL;
	}
	tmp = *head;
	while (tmp)
	{
		next = tmp->next;
		if (tmp->token_type == SP)
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			free(tmp->content);
			free(tmp);
		}
		tmp = next;
	}
}

t_token	*mn_tokenizer(char *line, t_env *envs)
{
	t_token	*head;

	head = NULL;
	if (mn_split_token(line, &head) == -1 || \
		mn_pre_env_token(&head, envs) == -1 || \
		mn_pre_sq_token(&head) == -1 || \
		mn_pre_str_token(&head) == -1)
	{
		mn_print_error(MALLOC, NULL);
		mn_destroy_token_lst(head);
		return (NULL);
	}
	mn_remove_sp_token(&head);
	return (head);
}
