/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_wait_all_child.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:08:33 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/23 20:15:15 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_exec.h"

void	mn_wait_all_child(int len)
{
	int		idx;
	int		status;
	int		flag;
	pid_t	child_pid;

	idx = 0;
	status = 0;
	flag = 0;
	while (idx < len)
	{
		child_pid = waitpid(-1, &status, 0);
		if (child_pid > 0)
		{
			if (mn_allocate_g_status(status) == 1)
				flag = 1;
		}
		idx++;
	}
	if (flag)
		write(1, "\n", 1);
}
