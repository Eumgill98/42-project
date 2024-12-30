/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_setting_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:25:46 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/03 18:28:03 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

void	mn_setting_free(t_mn_setting *setting)
{
	if (setting->pipes != NULL)
	{
		mn_destroy_pipes(setting->pipes, mn_processlen(setting->processes) - 1);
		free(setting->pipes);
	}
	if (setting->environment != NULL)
	{
		mn_destroy_environment(setting->environment);
		free(setting->environment);
	}
	if (setting->tokens != NULL)
		mn_destroy_token_lst(setting->tokens);
	if (setting->check_token_valid)
		free(setting->check_token_valid);
	if (setting->processes != NULL)
		mn_destroy_process(setting->processes);
	if (setting->origin_stdin != -1)
		close(setting->origin_stdin);
	if (setting->origin_stdout != -1)
		close(setting->origin_stdout);
	mn_setting_init(setting);
}
