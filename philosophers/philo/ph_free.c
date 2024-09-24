/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:09:40 by hocjeong          #+#    #+#             */
/*   Updated: 2024/09/24 17:10:56 by hocjeong         ###   ########.fr       */
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

void	ph_free_forks(pthread_mutex_t **forks, int target)
{
	int	idx;

	idx = 0;
	if (target == -1)
	{
		while (forks[idx])
		{
			pthread_mutex_destroy(forks[idx]);
			free(forks[idx]);
			forks[idx] = NULL;
			idx++;
		}
	}
	else
	{
		while (idx < target)
		{
			pthread_mutex_destroy(forks[idx]);
			free(forks[idx]);
			forks[idx] = NULL;
			idx++;
		}
	}
	free(forks);
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

void	ph_free_info(t_program *info)
{
	if (info->philos)
		ph_free_philos(info->philos, -1);
	if (info->forks)
		ph_free_forks(info->forks, -1);
	if (info->pthreads)
		ph_free_pthreads(info->pthreads, -1);
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
}
