/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_init_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:09:33 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/12 19:12:38 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

void	mn_init_process(t_process *process)
{
	process->next = NULL;
	process->command = NULL;
	process->built_in_type = NOT_BUILT_IN;
	process->redirects = NULL;
	process->args = NULL;
}
