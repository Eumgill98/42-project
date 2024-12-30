/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_malloc_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:59:15 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/12 13:00:22 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_error.h"

void	mn_malloc_error(void)
{
	write(2, ERROR_PROMPT, ft_strlen(ERROR_PROMPT));
	write(2, MALLOC_ERROR, ft_strlen(MALLOC_ERROR));
	write(2, "\n", 1);
	g_status = 1;
}
