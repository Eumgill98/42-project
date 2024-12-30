/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_split_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:43:58 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/10 16:38:54 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

static char	*extract_token(char *line, int s_idx, int e_idx)
{
	char	*tmp;
	int		idx;

	tmp = (char *)malloc(sizeof(char) * (e_idx - s_idx + 2));
	if (!tmp)
		return (NULL);
	idx = 0;
	while (s_idx <= e_idx)
	{
		tmp[idx] = line[s_idx];
		s_idx++;
		idx++;
	}
	tmp[idx] = '\0';
	return (tmp);
}

static int	update_end_idx(char *line, int e_idx, t_token_type start_type)
{
	if (start_type == DQ || start_type == SQ)
	{
		while (mn_check_token_s_type(line[e_idx]) != start_type)
			e_idx++;
		e_idx++;
	}
	else if (start_type == HEREDOC)
		e_idx = e_idx + 2;
	else if (start_type == APPEND)
		e_idx = e_idx + 2;
	else
	{
		while (mn_check_token_s_type(line[e_idx]) == start_type)
			e_idx++;
	}
	return (e_idx - 1);
}

static int	find_end_idx(char *line, int s_idx)
{
	t_token_type	start_type;
	int				e_idx;

	if (line[s_idx] == '\0')
		return (s_idx);
	start_type = mn_check_token_type(&line[s_idx]);
	if (start_type == SQ || start_type == DQ)
		e_idx = s_idx + 1;
	else
		e_idx = s_idx;
	e_idx = update_end_idx(line, e_idx, start_type);
	return (e_idx);
}

int	mn_split_token(char *line, t_token **head)
{
	int		s_idx;
	int		e_idx;
	t_token	*new;
	char	*tmp;

	s_idx = 0;
	while (line[s_idx])
	{
		e_idx = find_end_idx(line, s_idx);
		tmp = extract_token(line, s_idx, e_idx);
		if (!tmp)
			return (-1);
		new = mn_new_token(tmp);
		if (*head == NULL)
			*head = new;
		else
			mn_append_token(*head, new);
		s_idx = e_idx + 1;
		free(tmp);
	}
	new = mn_new_token("newline");
	if (new == NULL)
		return (-1);
	mn_append_token(*head, new);
	return (0);
}
