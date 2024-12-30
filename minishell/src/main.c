/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:15:24 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/19 19:59:50 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_status = 0;

static int	line_check(char *line, t_mn_setting *setting)
{
	if (line == NULL)
	{
		write(1, "exit\n", 5);
		mn_setting_exit(setting, 0);
	}
	if (mn_check_quote_closed(line) == -1)
	{
		mn_print_error(QUTOE, NULL);
		return (1);
	}
	if (*line == '\0' || *line == '\t')
		return (1);
	add_history(line);
	return (0);
}

static void	restore_stdin_stdout(t_mn_setting *setting)
{
	if (dup2(setting->origin_stdin, STDIN_FILENO) < 0 || \
		dup2(setting->origin_stdout, STDOUT_FILENO) < 0)
	{
		mn_print_re_error(DUP_FAIL, "BACK_UP_STDIN_STDOUT");
		mn_setting_exit(setting, 1);
	}
}

int	main(int ac, char **av, char **envp)
{
	char			*line;
	t_mn_setting	*setting;

	(void)ac;
	(void)av;
	setting = mn_setting_create(envp);
	while (1)
	{
		mn_set_parent_signal();
		line = readline(SHELL_PROMPOT);
		if (line_check(line, setting) == 0 && \
			mn_parsing(line, setting) == 0)
		{
			mn_set_ignore_parent_signal();
			mn_exec(setting);
		}
		restore_stdin_stdout(setting);
		free(line);
		mn_setting_token_init(setting);
	}
}
