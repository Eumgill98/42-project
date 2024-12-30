/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_check_token_s_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:01:30 by hocjeong          #+#    #+#             */
/*   Updated: 2024/11/21 20:03:21 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

t_token_type	mn_check_token_s_type(char c)
{
	if (c == '\'')
		return (SQ);
	else if (c == '"')
		return (DQ);
	else if (c == ' ')
		return (SP);
	else if (c == '\0')
		return (END);
	else if (c == '|')
		return (PIPE);
	else if (c == '>')
		return (OUT);
	else if (c == '<')
		return (IN);
	return (STR);
}
