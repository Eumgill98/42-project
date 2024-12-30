/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_close_origin_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:51:45 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/23 17:53:28 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_exec.h"

void	mn_close_origin_fd(t_mn_setting *setting)
{
	if (setting->origin_stdin != -1)
		close(setting->origin_stdin);
	if (setting->origin_stdout != -1)
		close(setting->origin_stdout);
	setting->origin_stdin = -1;
	setting->origin_stdout = -1;
}
