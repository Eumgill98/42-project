/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:28:40 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/27 16:02:15 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_environment.h"

static int	check_varname(char *s, int equal_idx)
{
	int	idx;
	int	exit_len;

	if (!(ft_isalpha(s[0]) || s[0] == '_'))
		return (-1);
	idx = 1;
	if (equal_idx == -1)
		exit_len = ft_strlen(s);
	else
		exit_len = equal_idx;
	while (idx < exit_len)
	{
		if (!(ft_isalnum(s[idx]) || s[idx] == '_' || \
		(idx == (exit_len - 1) && s[idx] == '+' && equal_idx != -1)))
			return (-1);
		idx++;
	}
	return (0);
}

int	get_equal_idx(char *s)
{
	int	idx;

	idx = 0;
	while (s[idx])
	{
		if (s[idx] == '=')
			return (idx);
		idx++;
	}
	return (-1);
}

char	*mn_parse_varname(char *s, int equal_idx, int *flag)
{
	if (equal_idx == 0 || s[0] == '\0' || check_varname(s, equal_idx))
	{
		mn_print_error(ASSIGNMENT, s);
		if (flag)
			(*flag) = 1;
		return (NULL);
	}
	if (equal_idx == -1)
		return (ft_strdup(s));
	return (ft_substr(s, 0, equal_idx));
}

char	*mn_parse_value(char *s, int equal_idx)
{
	if (equal_idx == 0 || s[0] == '\0' || check_varname(s, equal_idx))
		return (NULL);
	if (equal_idx == -1)
		return (NULL);
	return (ft_substr(s, equal_idx + 1, ft_strlen(s)));
}
