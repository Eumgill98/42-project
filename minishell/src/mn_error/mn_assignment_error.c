/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_assignment_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:18:05 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/12 13:21:41 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_error.h"

void	mn_assignment_error(char *parser_error)
{
	write(2, ERROR_PROMPT, ft_strlen(ERROR_PROMPT));
	write(2, "'", 1);
	write(2, parser_error, ft_strlen(parser_error));
	write(2, "'", 1);
	write(2, ": ", ft_strlen(": "));
	write(2, BAD_ASSIGNMENT, ft_strlen(BAD_ASSIGNMENT));
	write(2, "\n", 1);
	g_status = 1;
}
