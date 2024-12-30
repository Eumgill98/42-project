/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_exec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 08:08:10 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/19 18:14:29 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MN_EXEC_H
# define MN_EXEC_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include "mn_tokenizer.h"
# include "mn_built_in.h"

typedef struct s_files
{
	int	in_file;
	int	out_file;
}	t_files;

void	mn_exec(t_mn_setting *setting);
int		mn_do_built_in(t_mn_setting *setting, t_process *now);

t_files	mn_redirect(t_redirect *redirects);
int		mn_redirect_in(t_redirect *now);
int		mn_redirect_out(t_redirect *now);
int		mn_redirect_append(t_redirect *now);
int		mn_redirect_heredoc(t_redirect *now);
int		mn_redirect_error_code(t_files files);
void	mn_in_pipe(t_process *tmp, t_mn_setting *setting, t_files files);
void	mn_out_pipe(t_process *tmp, t_mn_setting *setting, t_files files);

void	mn_free_split_path(char **split_path);
char	*mn_check_access(t_env *envs, char *command);
int		mn_execve(t_process *now, t_mn_setting *setting);
void	mn_one_process(t_mn_setting *setting);
void	mn_multiple_process(t_mn_setting *setting);
void	mn_set_ignore_parent_signal(void);

void	mn_close_origin_fd(t_mn_setting *setting);
void	mn_wait_all_child(int len);

#endif
