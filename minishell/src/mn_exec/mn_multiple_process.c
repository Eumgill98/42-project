/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_multiple_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:13:37 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/27 15:50:32 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_exec.h"

static void	fork_fail(char *name, t_mn_setting *setting)
{
	mn_print_error(FORKS, name);
	mn_setting_exit(setting, 1);
}

static void	mn_head_child(t_process *tmp, t_mn_setting *setting, int len)
{
	t_files	files;
	int		flag;

	mn_set_child_signal(0);
	mn_close_origin_fd(setting);
	files = mn_redirect(tmp->redirects);
	if (files.in_file < 0 || files.out_file < 0)
		mn_setting_exit(setting, mn_redirect_error_code(files));
	if (tmp->next)
		mn_out_pipe(tmp, setting, files);
	mn_destroy_pipes(setting->pipes, len - 1);
	free(setting->pipes);
	setting->pipes = NULL;
	flag = 0;
	if (tmp->command)
		flag = mn_execve(tmp, setting);
	mn_setting_exit(setting, flag);
}

static void	mn_middle_child(t_process *tmp, t_mn_setting *setting, int len)
{
	t_files	files;
	int		flag;

	mn_set_child_signal(0);
	mn_close_origin_fd(setting);
	files = mn_redirect(tmp->redirects);
	if (files.in_file < 0 || files.out_file < 0)
		mn_setting_exit(setting, mn_redirect_error_code(files));
	mn_in_pipe(tmp, setting, files);
	mn_out_pipe(tmp, setting, files);
	mn_destroy_pipes(setting->pipes, len - 1);
	free(setting->pipes);
	setting->pipes = NULL;
	flag = 0;
	if (tmp->command)
		flag = mn_execve(tmp, setting);
	mn_setting_exit(setting, flag);
}

static void	mn_tail_child(t_process *tmp, t_mn_setting *setting, int len)
{
	t_files	files;
	int		flag;

	mn_set_child_signal(0);
	mn_close_origin_fd(setting);
	files = mn_redirect(tmp->redirects);
	if (files.in_file < 0 || files.out_file < 0)
		mn_setting_exit(setting, mn_redirect_error_code(files));
	mn_in_pipe(tmp, setting, files);
	mn_destroy_pipes(setting->pipes, len - 1);
	free(setting->pipes);
	setting->pipes = NULL;
	flag = 0;
	if (tmp->command)
		flag = mn_execve(tmp, setting);
	mn_setting_exit(setting, flag);
}

void	mn_multiple_process(t_mn_setting *setting)
{
	int			len;
	pid_t		pid;
	t_process	*tmp;

	tmp = setting->processes;
	len = mn_processlen(setting->processes);
	while (tmp)
	{
		pid = fork();
		if (pid == -1)
			fork_fail(tmp->command, setting);
		if (pid == 0 && tmp->process_idx == 0)
			mn_head_child(tmp, setting, len);
		else if (pid == 0 && tmp->process_idx >= 1 && \
			tmp->process_idx < (len - 1))
			mn_middle_child(tmp, setting, len);
		else if (pid == 0 && tmp->process_idx == (len - 1))
			mn_tail_child(tmp, setting, len);
		tmp = tmp->next;
	}
	mn_destroy_pipes(setting->pipes, len - 1);
	free(setting->pipes);
	setting->pipes = NULL;
	mn_wait_all_child(len);
}
