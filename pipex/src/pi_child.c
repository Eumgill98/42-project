/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:44:48 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/29 17:32:37 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	pi_head_child(t_pipeinfo *info, t_file *file, int *fd, int idx)
{
	dup2(fd[1], STDOUT_FILENO);
	dup2(file->input_file, STDIN_FILENO);
	close(fd[0]);
	return (pi_execute(info, info->commands[idx]));
}

static int	pi_middle_child(t_pipeinfo *info, int *fd, int idx)
{
	dup2(fd[1], STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	return (pi_execute(info, info->commands[idx]));
}

static int	pi_tail_child(t_pipeinfo *info, t_file *file, int *fd, int idx)
{
	dup2(fd[0], STDIN_FILENO);
	dup2(file->output_file, STDOUT_FILENO);
	close(fd[1]);
	return (pi_execute(info, info->commands[idx]));
}

int	pi_child(t_pipeinfo *info, t_file *file, int *fd)
{
	pid_t	pid;
	int		total_c;
	int		idx;

	total_c = info->num_commands;
	idx = 0;
	while (idx < total_c)
	{
		pid = fork();
		if (pid == -1)
			return (-1);
		if (pid == 0 && !idx)
			pi_head_child(info, file, fd, idx);
		else if (pid == 0 && idx > 0 && idx < (total_c - 1))
			pi_middle_child(info, fd, idx);
		else if (pid == 0 && idx == total_c - 1)
			pi_tail_child(info, file, fd, idx);
		else
			waitpid(pid, NULL, 0);
		idx++;
	}
	return (0);
}
