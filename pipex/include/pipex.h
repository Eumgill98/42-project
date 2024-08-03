/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:12:33 by hocjeong          #+#    #+#             */
/*   Updated: 2024/08/03 15:08:59 by hocjeong         ###   ########.fr       */
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
	int		o_fd;
	int		c_fd;
	int		infile;
	int		outfile;
}	t_pipeinfo;

t_pipeinfo	*pi_init_info(int ac, char **av, char **env);
int			pi_dstrlen(char **dstr);

int			pi_error(char *msg);
void		pi_exit(t_pipeinfo *info, char *msg);
void		pi_success_exit(t_pipeinfo *info, int *fd);

void		pi_freedstr_idx(char **dstr, int idx);
void		pi_freedstr(char **dstr);
void		pi_freeinfo(t_pipeinfo *info);
void		pi_freepipe(int *fd);

char		**pi_command(int ac, char **av);

char		*pi_path_join(char *s1, char *s2);
char		*pi_env_find(char **env);
char		**pi_env_split(char *path);
char		*pi_env_access(char **envs, char *command);

int			pi_child(t_pipeinfo *info, int *fd, int ac, char **av);

int			pi_execute(t_pipeinfo *info, char *command);
#endif
