/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:09:40 by hocjeong          #+#    #+#             */
/*   Updated: 2024/09/13 15:36:32 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_free_philos_idx(t_philo **philos, int target)
{
	int	idx;

	idx = 0;
	while (idx < target)
	{
		free(philos[idx]);
		idx++;
	}
	free(philos);
}

void	ph_free_philos(t_philo **philos)
{
	int	idx;

	idx = 0;
	while (philos[idx])
	{
		free(philos[idx]);
		idx++;
	}
	free(philos);
}

void	ph_free_forks_idx(pthread_mutex_t **forks, int target)
{
	int	idx;

	idx = 0;
	while (idx < target)
	{
		pthread_mutex_destroy(forks[idx]);
		idx++;
	}
	free(forks);
}

void	ph_free_forks(pthread_mutex_t **forks)
{
	int	idx;

	idx = 0;
	while (forks[idx])
	{
		pthread_mutex_destory(forks[idx]);
		idx++;
	}
	free(forks);
}
