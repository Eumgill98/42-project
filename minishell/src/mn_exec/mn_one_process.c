/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_one_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 07:55:52 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/21 09:09:16 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_exec.h"

void	mn_one_process(t_mn_setting *setting)
{
	t_files	files;

	files = mn_redirect(setting->processes->redirects);
	if (files.in_file < 0 || files.out_file < 0)
		return ;
	g_status = mn_do_built_in(setting, setting->processes);
}
