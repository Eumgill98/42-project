/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_processlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:19:25 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/16 10:33:01 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

int	mn_processlen(t_process *processes)
{
	t_process	*tmp;
	int			len;

	len = 0;
	tmp = processes;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}
