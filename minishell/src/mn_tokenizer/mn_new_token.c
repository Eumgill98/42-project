/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_new_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:17:35 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/10 16:45:07 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

t_token	*mn_new_token(char *content)
{
	t_token	*tmp;

	tmp = (t_token *)malloc(sizeof(t_token));
	if (!tmp)
		return (NULL);
	tmp->prev = NULL;
	tmp->next = NULL;
	tmp->content = ft_strdup(content);
	if (tmp->content == NULL)
	{
		free(tmp);
		return (NULL);
	}
	tmp->token_type = mn_check_token_type(content);
	return (tmp);
}
