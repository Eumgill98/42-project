/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_pipes_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:57:03 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/17 09:58:09 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_error.h"

void	mn_pipes_error(void)
{
	write(2, ERROR_PROMPT, ft_strlen(ERROR_PROMPT));
	write(2, PIPES_ERROR, ft_strlen(PIPES_ERROR));
	write(2, "\n", 1);
	g_status = 1;
}
