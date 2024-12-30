/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_new_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:33:10 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/19 18:16:28 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

static void	mn_free_pipes(int **new, int len)
{
	int	idx;

	idx = 0;
	while (idx < len)
	{
		free(new[idx]);
		idx++;
	}
}

static int	mn_allocate_pipe(int **new, int num_of_pipe)
{
	int	idx;
	int	*tmp;

	idx = 0;
	while (idx < num_of_pipe)
	{
		tmp = (int *)malloc(sizeof(int) * 2);
		if (!tmp)
		{
			mn_print_error(MALLOC, NULL);
			mn_free_pipes(new, idx);
			return (-1);
		}
		new[idx] = tmp;
		idx++;
	}
	return (0);
}

static int	mn_make_pipes(int **new, int num_of_pipe)
{
	int	idx;

	idx = 0;
	while (idx < num_of_pipe)
	{
		if (pipe(new[idx]) == -1)
		{
			mn_print_error(PIPES, NULL);
			mn_destroy_pipes(new, idx);
			return (-1);
		}
		idx++;
	}
	return (0);
}

int	**mn_new_pipes(int num_of_pipe)
{
	int	**new;

	if (num_of_pipe == 0)
		return (NULL);
	new = (int **)malloc(num_of_pipe * sizeof(int *));
	if (new == NULL)
	{
		mn_print_error(MALLOC, NULL);
		return (NULL);
	}
	if (mn_allocate_pipe(new, num_of_pipe) == -1)
	{
		free(new);
		return (NULL);
	}
	mn_init_pipes(new, num_of_pipe);
	if (mn_make_pipes(new, num_of_pipe) == -1)
	{
		free(new);
		return (NULL);
	}
	return (new);
}
