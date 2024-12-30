/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:35:20 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/13 18:51:29 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	mn_parsing(char *line, t_mn_setting *setting)
{
	setting->tokens = mn_tokenizer(line, setting->environment->envs);
	if (setting->tokens == NULL)
		return (-1);
	setting->check_token_valid = mn_check_token_valid(setting->tokens);
	if (setting->check_token_valid)
	{
		mn_print_error(PARSER, setting->check_token_valid);
		return (-1);
	}
	setting->processes = mn_processer(setting->tokens, setting);
	if (setting->processes == NULL)
		return (-1);
	setting->pipes = mn_new_pipes(mn_processlen(setting->processes) - 1);
	if (mn_processlen(setting->processes) > 1 && setting->pipes == NULL)
		return (-1);
	return (0);
}
