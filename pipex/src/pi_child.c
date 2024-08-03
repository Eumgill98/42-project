/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:44:48 by hocjeong          #+#    #+#             */
/*   Updated: 2024/08/03 14:10:37 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	pi_head_child(t_pipeinfo *info, int *fd, int idx, char *file)
{
	int	infile;

	infile = open(file, O_RDONLY);
	if (infile < 0)
	{
		close(fd[0]);
		close(fd[1]);
		pi_exit(info, file);
	}
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		close(fd[0]);
		close(fd[1]);
		close(infile);
		pi_exit(info, "dup2");
	}
	if (dup2(infile, STDIN_FILENO) == -1)
	{
		close(fd[0]);
		close(infile);
		pi_exit(info, "dup2");
	}
	close(fd[0]);
	return (pi_execute(info, info->commands[idx]));
}

static int	pi_middle_child(t_pipeinfo *info, int *fd, int idx)
{
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		close(fd[0]);
		close(fd[1]);
		pi_exit(info, "dup2");
	}
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		close(fd[0]);
		pi_exit(info, "dup2");
	}
	return (pi_execute(info, info->commands[idx]));
}

static int	pi_tail_child(t_pipeinfo *info, int *fd, int idx, char *file)
{
	int	outfile;

	outfile = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (outfile < 0)
	{
		close(fd[0]);
		close(fd[1]);
		pi_exit(info, file);
	}
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		close(fd[0]);
		close(fd[1]);
		close(outfile);
		pi_exit(info, "dup2");
	}
	if (dup2(outfile, STDOUT_FILENO) == -1)
	{
		close(fd[1]);
		close(outfile);
		pi_exit(info, "dup2");
	}
	close(fd[1]);
	return (pi_execute(info, info->commands[idx]));
}

int	pi_child(t_pipeinfo *info, int *fd, int ac, char **av)
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
			return (pi_head_child(info, fd, idx, av[1]));
		else if (pid == 0 && idx > 0 && idx < (total_c - 1))
			return (pi_middle_child(info, fd, idx));
		else if (pid == 0 && idx == total_c - 1)
			return (pi_tail_child(info, fd, idx, av[ac - 1]));
		idx++;
	}
	waitpid(-1, NULL, 0);
	return (0);
}
