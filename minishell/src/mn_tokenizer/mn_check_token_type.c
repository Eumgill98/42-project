/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_check_token_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:54:37 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/10 16:23:19 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

t_token_type	mn_check_token_type(char *s)
{
	if (s[0] == '\'')
		return (SQ);
	else if (s[0] == '"')
		return (DQ);
	else if (s[0] == ' ')
		return (SP);
	else if (s[0] == '\0' || ft_strcmp("newline", s) == 0)
		return (END);
	else if (s[0] == '|')
		return (PIPE);
	else if (s[0] == '>')
	{
		if (s[1] == '>')
			return (APPEND);
		return (OUT);
	}
	else if (s[0] == '<')
	{
		if (s[1] == '<')
			return (HEREDOC);
		return (IN);
	}
	return (STR);
}
