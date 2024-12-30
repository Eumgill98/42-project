/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_parser_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:01:04 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/12 13:02:37 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_error.h"

void	mn_parser_error(char *parser_error)
{
	write(2, ERROR_PROMPT, ft_strlen(ERROR_PROMPT));
	write(2, PARSER_ERROR, ft_strlen(PARSER_ERROR));
	write(2, parser_error, ft_strlen(parser_error));
	write(2, "\n", 1);
	g_status = 1;
}
