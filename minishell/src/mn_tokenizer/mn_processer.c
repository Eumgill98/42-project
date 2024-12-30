/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_processer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:47:14 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/13 17:58:56 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

static t_token	*mn_move_next_token(t_token *now)
{
	t_token	*tmp;

	tmp = now;
	while (tmp && tmp->token_type != PIPE && tmp->token_type != END)
		tmp = tmp->next;
	if (tmp && tmp->token_type == PIPE)
		tmp = tmp->next;
	if (tmp && tmp->token_type == END)
		tmp = tmp->next;
	return (tmp);
}

static void	mn_append_process(t_process **head, t_process *new)
{
	t_process	*tmp;

	tmp = *head;
	if (tmp == NULL)
		*head = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_process	*mn_processer(t_token *tokens, t_mn_setting *setting)
{
	t_process	*head;
	t_process	*new;
	t_token		*tmp_token;
	int			idx;

	head = NULL;
	tmp_token = tokens;
	idx = 0;
	while (tmp_token)
	{
		new = mn_new_process(tmp_token, idx, setting);
		if (new == NULL)
		{
			mn_destroy_process(head);
			return (NULL);
		}
		mn_append_process(&head, new);
		idx++;
		tmp_token = mn_move_next_token(tmp_token);
	}
	return (head);
}
