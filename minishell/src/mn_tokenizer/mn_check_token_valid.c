/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_check_token_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:58:47 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/03 18:10:54 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

char	*mn_check_token_valid(t_token *head)
{
	t_token			*tmp;
	t_token_type	prev_token;

	if (head == NULL)
		return (NULL);
	tmp = head;
	prev_token = STR;
	while (tmp)
	{
		if (tmp->token_type == SP)
		{
			tmp = tmp->next;
			if (tmp == NULL)
				break ;
		}
		if (prev_token == PIPE && \
			(tmp->token_type == PIPE || tmp->token_type == END))
			return (ft_strdup(tmp->content));
		prev_token = tmp->token_type;
		tmp = tmp->next;
	}
	return (NULL);
}
