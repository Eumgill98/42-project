/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_is_directory_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:41:59 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/27 15:43:00 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_exec.h"

void	mn_is_directory_error(char *name)
{
	write(2, ERROR_PROMPT, ft_strlen(ERROR_PROMPT));
	write(2, name, ft_strlen(name));
	write(2, ": ", ft_strlen(": "));
	write(2, IS_DIRECTORY_ERROR, ft_strlen(IS_DIRECTORY_ERROR));
	write(2, "\n", 1);
	g_status = 126;
}
