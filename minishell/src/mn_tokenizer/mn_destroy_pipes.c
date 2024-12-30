/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_destroy_pipes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:27:06 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/17 09:29:49 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

void	mn_destroy_pipes(int **pipes, int num_of_pipe)
{
	int	idx;

	idx = 0;
	while (idx < num_of_pipe)
	{
		if (pipes[idx][0] != -1)
		{
			close(pipes[idx][0]);
			pipes[idx][0] = -1;
		}
		if (pipes[idx][1] != -1)
		{
			close(pipes[idx][1]);
			pipes[idx][1] = -1;
		}
		free(pipes[idx]);
		pipes[idx] = NULL;
		idx++;
	}
}
