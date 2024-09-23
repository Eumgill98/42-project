/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:09:40 by hocjeong          #+#    #+#             */
/*   Updated: 2024/09/23 17:27:23 by hocjeong         ###   ########.fr       */
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

void	ph_free_info(t_program *info)
{
	if (info->philos)
	{
		ph_free_philos(info->philos, -1);
		info->philos = NULL;
	}	
	if (info->forks)
	{
		ph_free_forks(info->forks, -1);
		info->forks = NULL;
	}
	if (info->print_mutex)
	{
		pthread_mutex_destroy(info->print_mutex);
		free(info->print_mutex);
		info->print_mutex = NULL;
	}
	if (info->dead_mutex)
	{
		pthread_mutex_destroy(info->dead_mutex);
		free(info->dead_mutex);
		info->dead_mutex = NULL;
	}
}
