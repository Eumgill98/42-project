/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_dup2_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:54:35 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/18 15:58:51 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_error.h"

void	mn_dup2_error(char *name)
{
	write(2, ERROR_PROMPT, ft_strlen(ERROR_PROMPT));
	write(2, "'", 1);
	write(2, name, ft_strlen(name));
	write(2, "'", 1);
	write(2, ": ", ft_strlen(": "));
	write(2, DUP2_ERROR, ft_strlen(DUP2_ERROR));
	write(2, "\n", 1);
	g_status = 1;
}
