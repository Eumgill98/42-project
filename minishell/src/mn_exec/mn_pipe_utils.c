/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_pipe_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 18:00:09 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/27 15:48:26 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_exec.h"

void	mn_in_pipe(t_process *tmp, t_mn_setting *setting, t_files files)
{
	if (files.in_file < 1)
	{
		if (dup2(setting->pipes[tmp->process_idx - 1][0], STDIN_FILENO) == -1)
		{
			mn_print_re_error(DUP_FAIL, tmp->command);
			mn_setting_exit(setting, 1);
		}
	}
}

void	mn_out_pipe(t_process *tmp, t_mn_setting *setting, t_files files)
{
	if (files.out_file < 1)
	{
		if (dup2(setting->pipes[tmp->process_idx][1], STDOUT_FILENO) == -1)
		{
			mn_print_re_error(DUP_FAIL, tmp->command);
			mn_setting_exit(setting, 1);
		}
	}
}
