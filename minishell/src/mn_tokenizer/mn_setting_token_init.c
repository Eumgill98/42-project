/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_setting_token_init.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:29:42 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/12 02:03:01 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

void	mn_setting_token_init(t_mn_setting *setting)
{
	if (setting->pipes != NULL)
	{
		mn_destroy_pipes(setting->pipes, mn_processlen(setting->processes) - 1);
		free(setting->pipes);
		setting->pipes = NULL;
	}
	if (setting->tokens != NULL)
	{
		mn_destroy_token_lst(setting->tokens);
		setting->tokens = NULL;
	}
	if (setting->check_token_valid != NULL)
	{
		free(setting->check_token_valid);
		setting->check_token_valid = NULL;
	}
	if (setting->processes != NULL)
	{
		mn_destroy_process(setting->processes);
		setting->processes = NULL;
	}
}
