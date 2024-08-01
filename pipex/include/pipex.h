/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:12:33 by hocjeong          #+#    #+#             */
/*   Updated: 2024/08/01 17:17:09 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_pipeinfo
{
	char	**commands;
	int		num_commands;
	char	**envs;
}	t_pipeinfo;

typedef struct s_file
{
	int	input_file;
	int	output_file;
}	t_file;

t_pipeinfo	*pi_init_info(int ac, char **av, char **env);
t_file		*pi_init_file(int ac, char **av);
int			pi_dstrlen(char **dstr);

int			pi_error(char *msg);
void		pi_exit(t_pipeinfo *info, t_file *file, char *msg);
void		pi_success_exit(t_pipeinfo *info, t_file *file, int *fd);

void		pi_freedstr_idx(char **dstr, int idx);
void		pi_freedstr(char **dstr);
void		pi_freeinfo(t_pipeinfo *info);
void		pi_freefile(t_file *file);
void		pi_freepipe(int *fd);

char		**pi_command(int ac, char **av);

char		*pi_path_join(char *s1, char *s2);
char		*pi_env_find(char **env);
char		**pi_env_split(char *path);
char		*pi_env_access(char **envs, char *command);

int			pi_child(t_pipeinfo *info, t_file *file, int *fd);

int			pi_execute(t_pipeinfo *info, char *command);
#endif
