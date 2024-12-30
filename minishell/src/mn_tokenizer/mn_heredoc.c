/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:44:12 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/28 18:43:41 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

static void	mn_heredoc_child(int heredoc_pipe[2], char *sep, \
							t_mn_setting *setting)
{
	char	*line;
	char	*new_sep;

	mn_set_child_signal(1);
	new_sep = ft_strdup(sep);
	mn_free_heredoc_child(setting);
	close(heredoc_pipe[0]);
	while (1)
	{
		line = readline("> ");
		if (line == NULL)
			break ;
		if (ft_strcmp(line, new_sep) == 0)
		{
			free(line);
			break ;
		}
		add_history(line);
		write(heredoc_pipe[1], line, ft_strlen(line));
		write(heredoc_pipe[1], "\n", 1);
		free(line);
	}
	free(new_sep);
	close(heredoc_pipe[1]);
	exit(0);
}

static int	mn_heredoc_parent(int heredoc_pipe[2])
{
	int	heredoc_fd;

	heredoc_fd = dup(STDIN_FILENO);
	close(heredoc_pipe[1]);
	dup2(heredoc_pipe[0], heredoc_fd);
	close(heredoc_pipe[0]);
	return (heredoc_fd);
}

static int	pid_error(pid_t pid, int heredoc_pipe[2])
{
	if (pid == -1)
	{
		mn_print_error(FORKS, NULL);
		close(heredoc_pipe[0]);
		close(heredoc_pipe[1]);
		return (-1);
	}
	return (0);
}

static int	return_fd(int fd, int status)
{
	mn_allocate_g_status(status);
	if (g_status == 130 || g_status == 131)
	{
		write(1, "\n", 1);
		if (fd > 0)
			close(fd);
		return (-1);
	}
	return (fd);
}

int	mn_heredoc(char *sep, t_mn_setting *setting)
{
	int		heredoc_pipe[2];
	int		status;
	int		fd;
	pid_t	pid;

	mn_set_child_heredoc_signal();
	status = 0;
	if (pipe(heredoc_pipe) == -1)
	{
		mn_print_error(PIPES, NULL);
		return (-1);
	}
	pid = fork();
	if (pid_error(pid, heredoc_pipe) == -1)
		return (-1);
	if (pid == 0)
		mn_heredoc_child(heredoc_pipe, sep, setting);
	else
	{
		fd = mn_heredoc_parent(heredoc_pipe);
		waitpid(pid, &status, 0);
	}
	return (return_fd(fd, status));
}
