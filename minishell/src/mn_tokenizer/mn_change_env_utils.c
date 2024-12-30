/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_change_env_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:14:05 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/19 19:59:24 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

char	*search_env_value(char *var_name, t_env *envs)
{
	if (!var_name || !envs)
		return (NULL);
	while (envs)
	{
		if (ft_strcmp(envs->varname, var_name) == 0)
			return (ft_strdup(envs->value));
		envs = envs->next;
	}
	return (ft_strdup(""));
}

char	*resolve_env_var(char *s, int *idx, t_env *envs)
{
	char	*var_name;
	char	*result;
	int		start;
	int		len;

	(*idx)++;
	start = *idx;
	if (s[*idx] == '?')
	{
		(*idx)++;
		return (ft_itoa(g_status));
	}
	while (s[*idx] && (ft_isalnum(s[*idx]) || s[*idx] == '_'))
		(*idx)++;
	len = *idx - start;
	if (len == 0)
		return (ft_strdup("$"));
	var_name = ft_substr(s, start, len);
	result = search_env_value(var_name, envs);
	if (!result)
		return (NULL);
	free(var_name);
	return (result);
}

char	*extract_substr(char *s, int *idx)
{
	int		start;
	int		len;
	char	*substr;

	start = *idx;
	while (s[*idx] && s[*idx] != '$' && s[*idx] != '"')
		(*idx)++;
	len = *idx - start;
	substr = ft_substr(s, start, len);
	(*idx)--;
	return (substr);
}
