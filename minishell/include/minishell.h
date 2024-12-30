/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:17:07 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/21 12:36:28 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>              
# include <termios.h>

# include "mn_tokenizer.h"
# include "mn_environment.h"
# include "mn_exec.h"
# include "mn_error.h"

void	mn_set_parent_signal(void);
int		mn_parsing(char *line, t_mn_setting *setting);
#endif
