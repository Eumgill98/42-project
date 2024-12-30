/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_cant_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 18:42:19 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/24 18:44:54 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_error.h"

void	mn_cant_error(char *name)
{
	write(2, ERROR_PROMPT, ft_strlen(ERROR_PROMPT));
	write(2, "'", 1);
	write(2, name, ft_strlen(name));
	write(2, "'", 1);
	write(2, ": ", ft_strlen(": "));
	write(2, CANT_ERROR, ft_strlen(CANT_ERROR));
	write(2, "\n", 1);
	g_status = 1;
}
