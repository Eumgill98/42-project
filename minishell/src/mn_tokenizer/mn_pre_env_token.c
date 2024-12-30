/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_pre_env_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:28:17 by hocjeong          #+#    #+#             */
/*   Updated: 2024/11/21 20:48:14 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

int	mn_pre_env_token(t_token **head, t_env *envs)
{
	t_token	*tmp;
	char	*new;

	tmp = *head;
	while (tmp)
	{
		if (tmp->token_type == STR || tmp->token_type == DQ)
		{
			if (ft_strcmp(tmp->content, "\"\"") == 0)
				new = ft_strdup("");
			else
				new = mn_change_env(tmp->content, envs);
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
