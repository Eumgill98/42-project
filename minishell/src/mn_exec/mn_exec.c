/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 08:20:47 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/21 07:51:47 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_exec.h"

static int	mn_check_one_process(t_process *head)
{
	if (mn_processlen(head) == 1 && head->command == NULL)
		return (1);
	if (mn_processlen(head) == 1 && head->built_in_type != NOT_BUILT_IN)
		return (1);
	return (0);
}

void	mn_exec(t_mn_setting *setting)
{
	if (mn_check_one_process(setting->processes))
		mn_one_process(setting);
	else
		mn_multiple_process(setting);
}
