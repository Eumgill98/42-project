/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_new_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:13:31 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/12 20:03:09 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

static int	mn_str_processing(t_process *new, t_token *tmp)
{
	t_arg	*tmp_args;
	t_arg	*last;

	if (new->command == NULL)
	{
		new->command = ft_strdup(tmp->content);
		if (new->command == NULL)
			return (-1);
		new->built_in_type = mn_check_built_in_type(tmp->content);
		return (0);
	}
	tmp_args = mn_new_arg(tmp->content);
	if (tmp_args == NULL)
		return (-1);
	if (new->args == NULL)
		new->args = tmp_args;
	else
	{
		last = new->args;
		while (last->next)
			last = last->next;
		last->next = tmp_args;
	}
	return (0);
}

static int	mn_redirect_processing(t_process *new, t_token *tmp, \
			t_mn_setting *setting)
{
	t_redirect	*tmp_redirect;
	t_redirect	*last;

	tmp_redirect = mn_new_redirect(tmp->token_type, \
						tmp->next->content, setting);
	if (tmp_redirect == NULL)
		return (-1);
	if (new->redirects == NULL)
		new->redirects = tmp_redirect;
	else
	{
		last = new->redirects;
		while (last->next)
			last = last->next;
		last->next = tmp_redirect;
	}
	return (0);
}

static t_token	*mn_move_next_token(t_token *tmp)
{
	if (tmp->token_type == OUT || tmp->token_type == IN || \
		tmp->token_type == HEREDOC || tmp->token_type == APPEND)
		return (tmp->next->next);
	return (tmp->next);
}

static int	mn_processing(t_process **new, t_token *tmp, t_mn_setting *setting)
{
	if (tmp->token_type == STR && ft_strcmp(tmp->content, "") != 0)
		return (mn_str_processing(*new, tmp));
	if (tmp->token_type == OUT || tmp->token_type == IN || \
		tmp->token_type == HEREDOC || tmp->token_type == APPEND)
		return (mn_redirect_processing(*new, tmp, setting));
	return (0);
}

t_process	*mn_new_process(t_token *token, int idx, t_mn_setting *setting)
{
	t_process	*new;
	t_token		*tmp;

	if (token == NULL)
		return (NULL);
	new = (t_process *)malloc(sizeof(t_process));
	if (new == NULL)
		return (NULL);
	mn_init_process(new);
	tmp = token;
	while (tmp && tmp->token_type != PIPE && tmp->token_type != END)
	{
		if (mn_processing(&new, tmp, setting) == -1)
		{
			mn_del_process(new);
			free(new);
			return (NULL);
		}
		tmp = mn_move_next_token(tmp);
	}
	new->process_idx = idx;
	return (new);
}
