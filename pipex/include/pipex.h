/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:12:33 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/24 20:15:55 by hocjeong         ###   ########.fr       */
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
	char	**envs;
}	t_pipeinfo;

void	pi_freedstr(char **dstr, int idx);
void	pi_freeinfo(t_pipeinfo *info);

int		pi_init_info(int ac, char **av, char **env, t_pipeinfo *info);

char	**pi_command(int ac, char **av);

char	*pi_path_join(char *s1, char *s2);
char	*pi_env_find(char **env);
char	**pi_env_split(char *path);
char	*pi_env_access(char **envs, char *command);

#endif
