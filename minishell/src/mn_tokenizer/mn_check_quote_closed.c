/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_check_quote_closed.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:10:24 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/22 17:49:58 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

static int	find_matching_quote(const char *str, int start_idx, char quote)
{
	int	i;

	i = start_idx + 1;
	while (str[i] != '\0')
	{
		if (str[i] == quote)
			return (i);
		i++;
	}
	return (-1);
}

int	mn_check_quote_closed(char *line)
{
	int	i;
	int	matching_idx;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '"')
		{
			matching_idx = find_matching_quote(line, i, '"');
			if (matching_idx == -1)
				return (-1);
			i = matching_idx;
		}
		else if (line[i] == '\'')
		{
			matching_idx = find_matching_quote(line, i, '\'');
			if (matching_idx == -1)
				return (-1);
			i = matching_idx;
		}
		i++;
	}
	return (0);
}
