/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_pre_str_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:00:10 by hocjeong          #+#    #+#             */
/*   Updated: 2024/11/25 19:48:02 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

static int	merge_str_token(t_token *now)
{
	char	*new;
	t_token	*tmp;

	new = ft_strjoin(now->content, now->next->content);
	if (!new)
		return (-1);
	free(now->content);
	tmp = now->next->next;
	free(now->next->content);
	free(now->next);
	now->next = tmp;
	now->content = new;
	if (tmp != NULL)
		tmp->prev = now;
	return (0);
}

int	mn_pre_str_token(t_token **head)
{
	t_token	*tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		if (tmp->token_type == STR && tmp->next != NULL)
		{
			while (tmp->next != NULL && \
				tmp->next->token_type == STR)
			{
				if (merge_str_token(tmp) == -1)
					return (-1);
			}
		}
		tmp = tmp->next;
	}
	return (0);
}
