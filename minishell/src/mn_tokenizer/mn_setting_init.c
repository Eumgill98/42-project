/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_setting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:55:13 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/03 18:28:44 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

void	mn_setting_init(t_mn_setting *setting)
{
	setting->environment = NULL;
	setting->tokens = NULL;
	setting->processes = NULL;
	setting->pipes = NULL;
	setting->check_token_valid = NULL;
	setting->origin_stdin = -1;
	setting->origin_stdout = -1;
	setting->envp = NULL;
}
