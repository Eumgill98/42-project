/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_setting_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:22:42 by hocjeong          #+#    #+#             */
/*   Updated: 2024/11/26 22:28:40 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

int	mn_setting_env(char **envp, t_mn_setting *setting)
{
	setting->environment = mn_make_environment(envp);
	if (setting->environment == NULL)
		return (-1);
	setting->origin_stdin = dup(STDIN_FILENO);
	setting->origin_stdout = dup(STDOUT_FILENO);
	return (0);
}
