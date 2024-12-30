/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_out_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:07:08 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/18 16:08:12 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_error.h"

void	mn_out_error(char *name)
{
	write(2, ERROR_PROMPT, ft_strlen(ERROR_PROMPT));
	write(2, "'", 1);
	write(2, name, ft_strlen(name));
	write(2, "'", 1);
	write(2, ": ", ft_strlen(": "));
	write(2, OUT_ERROR, ft_strlen(OUT_ERROR));
	write(2, "\n", 1);
	g_status = 1;
}
