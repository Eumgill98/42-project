/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_built_in.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:00:20 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/22 15:23:06 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MN_BUILT_IN_H
# define MN_BUILT_IN_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "mn_tokenizer.h"
# include "mn_environment.h"
# include "libft.h"

int		mn_echo(t_arg *head);
int		mn_pwd(void);
int		mn_cd(t_environment *environment, t_arg *head);
int		mn_export(t_environment *environment, t_arg *head);
int		mn_unset(t_environment *environment, t_arg *head);
int		mn_exit(t_mn_setting *setting, t_arg *head);
void	mn_env(t_env *envs);

char	*get_directory_path(char *path);
#endif
