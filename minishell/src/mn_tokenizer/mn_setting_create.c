/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_setting_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:25:39 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/09 16:33:17 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

t_mn_setting	*mn_setting_create(char **envp)
{
	t_mn_setting	*setting;

	setting = (t_mn_setting *)malloc(sizeof(t_mn_setting));
	if (setting == NULL)
	{
		mn_print_error(MALLOC, NULL);
		mn_setting_exit(setting, 1);
	}
	mn_setting_init(setting);
	if (mn_setting_env(envp, setting) == -1)
		mn_setting_exit(setting, 1);
	setting->envp = envp;
	return (setting);
}
