/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_environment.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:55:33 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/07 17:50:47 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MN_ENVIRONMENT_H
# define MN_ENVIRONMENT_H

# include <stdlib.h>
# include <stdio.h>  
# include <unistd.h>
# include "libft.h"
# include "mn_error.h"

typedef struct s_env
{
	char			*varname;
	char			*value;
	struct s_env	*prev;
	struct s_env	*next;
}	t_env;

typedef struct s_environment
{
	t_env	*envs;
	t_env	*exports;
}	t_environment;

int				get_equal_idx(char *s);
char			*mn_parse_varname(char *s, int equal_idx, int *flag);
char			*mn_parse_value(char *s, int equal_idx);

int				mn_make_env_lst(char **envp, t_env **env, char export_flag);

t_env			*mn_new_env(char *varname, char *value);
t_environment	*mn_make_environment(char **envp);
void			mn_insert_envs(t_env **envs, t_env *new);
void			mn_insert_exports(t_env **exports, t_env *new);
void			mn_update_envs(t_env **envs, char **varname, char *value);
void			mn_update_exports(t_env **exports, char **varname, char *value);

void			insert_at_head(t_env **head, t_env *new);
void			insert_at_tail(t_env *tail, t_env *new);

void			mn_destroy_env(t_env *env);
void			mn_destroy_env_lst(t_env *head);
void			mn_destroy_environment(t_environment *environment);

void			mn_print_env_lst(t_env *head, int export_flag);
int				mn_check_in_env(t_env *envs, char *varname);
void			mn_change_env_value(t_env **exports, char *varname, \
									char *value, int plus);
int				mn_check_plus(char **varname);

#endif
