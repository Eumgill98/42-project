/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:57:09 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/19 18:17:05 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MN_ERROR_H
# define MN_ERROR_H

# include <errno.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h> 
# include "libft.h"

# define SHELL_PROMPOT "NEXT_SHELL: "
# define ERROR_PROMPT "nextshell_error: "
# define MALLOC_ERROR "malloc error"
# define QUTOE_ERROR "qutoe is not closed"
# define PARSER_ERROR "parse error near "
# define BAD_ASSIGNMENT "not a valid identifier"
# define TOO_MANY_ARG_ERROR "too many arguments"
# define EXIT_NUMERIC_ERROR "numeric argumnet required"
# define PIPES_ERROR "pipe error"
# define OPEN_ERROR "No such file or directory"
# define CANT_ERROR "Permission Denied"
# define OUT_ERROR "Make out file or directory failed"
# define DUP2_ERROR "Error : dup2 failed"
# define FORK_ERROR "fail to fork"
# define NOT_COMMAND_ERROR "command not found"
# define IS_DIRECTORY_ERROR "Is a directory"

extern int	g_status;

typedef enum s_error_type
{
	PERROR,
	MALLOC,
	QUTOE,
	PARSER,
	ASSIGNMENT,
	PIPES,
	FORKS,
	NOT_COMMAND,
	IS_DIRECTORY
}	t_error_type;

typedef enum s_re_error_type
{
	OPEN_FILE,
	OUT_FILE,
	CANT_FILE,
	DUP_FAIL
}	t_re_error_type;

void	mn_print_error(t_error_type error_type, char *parser_error);
void	mn_malloc_error(void);
void	mn_parser_error(char *parser_error);
void	mn_qutoe_error(void);
void	mn_assignment_error(char *parser_error);
void	mn_many_arg_error(char *name);
void	mn_exit_numeric_error(char *args);
void	mn_pipes_error(void);
void	mn_forks_error(char *name);
void	mn_not_command_error(char *name);
void	mn_is_directory_error(char *name);

void	mn_print_re_error(t_re_error_type error_type, char *name);
void	mn_open_error(char *name);
void	mn_cant_error(char *name);
void	mn_out_error(char *name);
void	mn_dup2_error(char *name);

#endif
