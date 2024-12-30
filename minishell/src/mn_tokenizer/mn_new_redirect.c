/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_new_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:15:52 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/28 18:45:48 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

t_redirect	*mn_new_redirect(t_token_type r_type, char *content, \
											t_mn_setting *setting)
{
	t_redirect	*new;

	new = (t_redirect *)malloc(sizeof(t_redirect));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->heredoc_fd = 0;
	new->file = NULL;
	if (r_type == HEREDOC)
		new->heredoc_fd = mn_heredoc(content, setting);
	else
		new->file = ft_strdup(content);
	if (new->heredoc_fd == -1 && new->file == NULL)
	{
		mn_del_redirect(new);
		free(new);
		return (NULL);
	}
	new->redirect_type = r_type;
	return (new);
}
