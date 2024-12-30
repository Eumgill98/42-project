/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_free_heredoc_child.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:28:41 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/24 16:29:59 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_exec.h"

void	mn_free_heredoc_child(t_mn_setting *setting)
{
	mn_setting_free(setting);
	if (setting != NULL)
		free(setting);
	setting = NULL;
}
