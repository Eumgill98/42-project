/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_allocate_g_status.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:09:05 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/21 17:11:00 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_exec.h"

int	mn_allocate_g_status(int status)
{
	if (WIFEXITED(status))
	{
		g_status = WEXITSTATUS(status);
		if (g_status == 130)
			return (1);
	}
	else if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) + 128 != 141)
			return (1);
		g_status = WTERMSIG(status) + 128;
	}
	return (0);
}
