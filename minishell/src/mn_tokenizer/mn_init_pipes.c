/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_init_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:44:24 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/17 09:45:24 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

void	mn_init_pipes(int **pipes, int num_of_pipe)
{
	int	idx;

	idx = 0;
	while (idx < num_of_pipe)
	{
		pipes[idx][0] = -1;
		pipes[idx][1] = -1;
		idx++;
	}
}
