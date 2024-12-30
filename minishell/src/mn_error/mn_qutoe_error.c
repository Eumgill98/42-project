/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_qutoe_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:03:29 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/12 13:04:36 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_error.h"

void	mn_qutoe_error(void)
{
	write(2, ERROR_PROMPT, ft_strlen(ERROR_PROMPT));
	write(2, QUTOE_ERROR, ft_strlen(QUTOE_ERROR));
	write(2, "\n", 1);
	g_status = 1;
}
