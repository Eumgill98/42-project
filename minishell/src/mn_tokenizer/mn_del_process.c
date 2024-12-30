/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_del_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:47:07 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/12 19:50:45 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

void	mn_del_process(t_process *process)
{
	if (process->command)
		free(process->command);
	if (process->redirects)
		mn_destroy_redirects(process->redirects);
	if (process->args)
		mn_destroy_args(process->args);
	process->command = NULL;
	process->redirects = NULL;
	process->args = NULL;
	process->built_in_type = NOT_BUILT_IN;
}
