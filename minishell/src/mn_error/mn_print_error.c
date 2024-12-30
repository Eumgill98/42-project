/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:00:23 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/19 18:19:31 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_error.h"

void	mn_print_error(t_error_type error_type, char *parser_error)
{
	if (error_type == PERROR)
		perror(ERROR_PROMPT);
	else if (error_type == MALLOC)
		mn_malloc_error();
	else if (error_type == PARSER)
		mn_parser_error(parser_error);
	else if (error_type == QUTOE)
		mn_qutoe_error();
	else if (error_type == ASSIGNMENT)
		mn_assignment_error(parser_error);
	else if (error_type == PIPES)
		mn_pipes_error();
	else if (error_type == FORKS)
		mn_forks_error(parser_error);
	else if (error_type == NOT_COMMAND)
		mn_not_command_error(parser_error);
	else if (error_type == IS_DIRECTORY)
		mn_is_directory_error(parser_error);
}
