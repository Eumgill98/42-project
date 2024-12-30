/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_do_built_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:13:15 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/16 12:02:40 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_exec.h"

int	mn_do_built_in(t_mn_setting *setting, t_process *now)
{
	if (now->built_in_type == MN_CD)
		return (mn_cd(setting->environment, now->args));
	if (now->built_in_type == MN_ECHO)
		return (mn_echo(now->args));
	if (now->built_in_type == MN_PWD)
		return (mn_pwd());
	if (now->built_in_type == MN_ENV)
		mn_env(setting->environment->envs);
	if (now->built_in_type == MN_EXPORT)
		return (mn_export(setting->environment, now->args));
	if (now->built_in_type == MN_UNSET)
		return (mn_unset(setting->environment, now->args));
	if (now->built_in_type == MN_EXIT)
		return (mn_exit(setting, now->args));
	return (0);
}
