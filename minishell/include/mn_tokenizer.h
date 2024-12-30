/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_tokenizer.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:13:41 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/28 19:53:40 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MN_TOKENIZER_H
# define MN_TOKENIZER_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>  
# include "libft.h"
# include "mn_environment.h"
# include "mn_error.h"

typedef enum s_token_type
{
	PIPE,
	OUT,
	IN,
	HEREDOC,
	APPEND,
	SP,
	SQ,
	DQ,
	STR,	
	END
}	t_token_type;

typedef enum s_built_in_type
{
	MN_CD,
	MN_ECHO,
	MN_ENV,
	MN_EXIT,
	MN_EXPORT,
	MN_PWD,
	MN_UNSET,
	NOT_BUILT_IN
}	t_built_in_type;	

typedef struct s_token
{
	struct s_token	*prev;
	struct s_token	*next;
	char			*content;
	t_token_type	token_type;
}	t_token;

typedef struct s_redirect
{
	struct s_redirect	*next;
	t_token_type		redirect_type;
	char				*file;
	int					heredoc_fd;
}	t_redirect;

typedef struct s_arg
{
	struct s_arg	*next;
	char			*arg;
}	t_arg;

typedef struct s_process
{
	struct s_process	*next;
	char				*command;
	int					process_idx;
	t_built_in_type		built_in_type;
	t_redirect			*redirects;
	t_arg				*args;
}	t_process;

typedef struct s_mn_setting
{
	t_environment	*environment;
	t_token			*tokens;
	t_process		*processes;
	int				**pipes;
	char			*check_token_valid;
	int				origin_stdin;
	int				origin_stdout;
	char			**envp;
}	t_mn_setting;

char			*search_env_value(char *var_name, t_env *envs);
char			*resolve_env_var(char *s, int *idx, t_env *envs);
char			*extract_substr(char *s, int *idx);
char			*mn_change_env(char *content, t_env *envs);

int				mn_check_quote_closed(char *line);
void			mn_append_token(t_token *head, t_token *new);
int				mn_split_token(char *line, t_token **head);
int				mn_pre_env_token(t_token **head, t_env *envs);
int				mn_pre_sq_token(t_token **head);
int				mn_pre_str_token(t_token **head);
char			*mn_check_token_valid(t_token *head);
t_token			*mn_tokenizer(char *line, t_env *envs);

t_token_type	mn_check_token_type(char *s);
t_token_type	mn_check_token_s_type(char c);
t_token			*mn_new_token(char *content);
void			mn_destroy_token_lst(t_token *head);

t_built_in_type	mn_check_built_in_type(char *s);
void			mn_init_process(t_process *process);
t_process		*mn_new_process(t_token *token, int idx, \
				t_mn_setting *mn_setting_token_init);
void			mn_del_process(t_process *process);
void			mn_destroy_process(t_process *head);
t_arg			*mn_new_arg(char *arg);
void			mn_del_arg(t_arg *arg);
void			mn_destroy_args(t_arg *head);
t_redirect		*mn_new_redirect(t_token_type r_type, \
				char *content, t_mn_setting *setting);
void			mn_del_redirect(t_redirect *redirect);
void			mn_destroy_redirects(t_redirect *head);
t_process		*mn_processer(t_token *tokens, t_mn_setting *setting);
int				mn_processlen(t_process *processes);
int				mn_arglen(t_arg *args);
int				mn_heredoc(char *sep, t_mn_setting *setting);

void			mn_destroy_pipes(int **pipes, int num_of_pipe);
void			mn_init_pipes(int **pipes, int num_of_pipe);
int				**mn_new_pipes(int num_of_pipe);

t_mn_setting	*mn_setting_create(char **envp);
void			mn_setting_init(t_mn_setting *setting);
void			mn_setting_free(t_mn_setting *setting);
int				mn_setting_env(char **envp, t_mn_setting *setting);
void			mn_setting_token_init(t_mn_setting *setting);
void			mn_setting_exit(t_mn_setting *setting, int exit_status);

int				mn_allocate_g_status(int status);
void			mn_set_child_signal(int heredoc);
void			mn_set_child_heredoc_signal(void);
void			mn_free_heredoc_child(t_mn_setting *setting);

#endif
