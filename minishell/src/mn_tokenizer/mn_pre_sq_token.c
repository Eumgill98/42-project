/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_pre_sq_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:34:57 by hocjeong          #+#    #+#             */
/*   Updated: 2024/11/25 17:57:43 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

static char	*mn_remove_sq(char *content)
{
	int		origin_len;
	int		idx;
	int		origin_idx;
	char	*tmp;

	origin_len = ft_strlen(content);
	tmp = (char *)malloc(sizeof(char) *(origin_len - 1));
	if (!tmp)
		return (NULL);
	idx = 0;
	origin_idx = 1;
	while (origin_idx < (origin_len - 1))
	{
		tmp[idx] = content[origin_idx];
		idx++;
		origin_idx++;
	}
	tmp[idx] = 0;
	return (tmp);
}

int	mn_pre_sq_token(t_token **head)
{
	t_token	*tmp;
	char	*new;

	tmp = *head;
	while (tmp)
	{
		if (tmp->token_type == SQ)
		{
			new = mn_remove_sq(tmp->content);
			if (new == NULL)
				return (-1);
			free(tmp->content);
			tmp->content = new;
			tmp->token_type = STR;
		}
		tmp = tmp->next;
	}
	return (0);
}
