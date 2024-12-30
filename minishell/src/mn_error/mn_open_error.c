/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_open_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:40:48 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/18 15:55:27 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_error.h"

void	mn_open_error(char *name)
{
	write(2, ERROR_PROMPT, ft_strlen(ERROR_PROMPT));
	write(2, "'", 1);
	write(2, name, ft_strlen(name));
	write(2, "'", 1);
	write(2, ": ", ft_strlen(": "));
	write(2, OPEN_ERROR, ft_strlen(OPEN_ERROR));
	write(2, "\n", 1);
	g_status = 1;
}
