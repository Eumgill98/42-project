/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_not_command_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:35:11 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/21 10:35:28 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_error.h"

void	mn_not_command_error(char *name)
{
	write(2, ERROR_PROMPT, ft_strlen(ERROR_PROMPT));
	write(2, name, ft_strlen(name));
	write(2, ": ", ft_strlen(": "));
	write(2, NOT_COMMAND_ERROR, ft_strlen(NOT_COMMAND_ERROR));
	write(2, "\n", 1);
	g_status = 127;
}
