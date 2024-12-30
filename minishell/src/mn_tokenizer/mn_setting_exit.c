/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_setting_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:03:40 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/16 11:59:10 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

void	mn_setting_exit(t_mn_setting *setting, int exit_status)
{
	mn_setting_free(setting);
	if (setting != NULL)
	{
		free(setting);
		setting = NULL;
	}
	exit(exit_status);
}
