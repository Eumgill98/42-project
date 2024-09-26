/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:09:40 by hocjeong          #+#    #+#             */
/*   Updated: 2024/09/26 16:42:07 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_free_philos(t_philo **philos, int target)
{
	int	idx;

	idx = 0;
	if (target == -1)
	{	
		while (philos[idx])
		{
			free(philos[idx]);
			idx++;
		}
	}
	else
	{
		while (idx < target)
		{
			free(philos[idx]);
			idx++;
		}
	}
	free(philos);
}

void	ph_free_mutexs(pthread_mutex_t **mutexs, int target)
{
	int	idx;

	idx = 0;
	if (target == -1)
	{
		while (mutexs[idx])
		{
			pthread_mutex_destroy(mutexs[idx]);
			free(mutexs[idx]);
			mutexs[idx] = NULL;
			idx++;
		}
	}
	else
	{
		while (idx < target)
		{
			pthread_mutex_destroy(mutexs[idx]);
			free(mutexs[idx]);
			mutexs[idx] = NULL;
			idx++;
		}
	}
	free(mutexs);
}

void	ph_free_pthreads(pthread_t **pthreads, int target)
{
	int	idx;

	idx = 0;
	if (target == -1)
	{
		while (pthreads[idx])
		{
			free(pthreads[idx]);
			pthreads[idx] = NULL;
			idx++;
		}
	}
	else
	{
		while (idx < target)
		{
			free(pthreads[idx]);
			pthreads[idx] = NULL;
			idx++;
		}
	}
	free(pthreads);
}

static void	ph_all_mutexs(t_program *info)
{
	if (info->forks)
		ph_free_mutexs(info->forks, -1);
	if (info->last_eaten_mutexs)
		ph_free_mutexs(info->last_eaten_mutexs, -1);
	if (info->eat_count_mutexs)
		ph_free_mutexs(info->eat_count_mutexs, -1);
	if (info->print_mutex)
	{
		pthread_mutex_destroy(info->print_mutex);
		free(info->print_mutex);
	}
	if (info->dead_mutex)
	{
		pthread_mutex_destroy(info->dead_mutex);
		free(info->dead_mutex);
	}
	if (info->end_mutex)
	{
		pthread_mutex_destroy(info->end_mutex);
		free(info->end_mutex);
	}
}

void	ph_free_info(t_program *info)
{
	if (info->philos)
		ph_free_philos(info->philos, -1);
	if (info->pthreads)
		ph_free_pthreads(info->pthreads, -1);
	ph_all_mutexs(info);
}
