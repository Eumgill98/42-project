/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_mutex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:20:06 by hocjeong          #+#    #+#             */
/*   Updated: 2024/09/30 20:28:14 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*ph_malloc_mutex(void)
{
	pthread_mutex_t	*new;

	new = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (new == NULL)
		return (NULL);
	if (pthread_mutex_init(new, NULL) == 0)
		return (new);
	return (NULL);
}

pthread_mutex_t	**ph_malloc_dmutex(int len)
{
	int				idx;
	pthread_mutex_t	**target;
	pthread_mutex_t	*tmp;

	target = (pthread_mutex_t **)malloc(sizeof(pthread_mutex_t *) \
				* (len + 1));
	if (target == NULL)
		return (NULL);
	idx = 0;
	while (idx < len)
	{
		tmp = ph_malloc_mutex();
		if (tmp == NULL)
		{
			ph_free_mutexs(target, idx);
			return (NULL);
		}
		target[idx] = tmp;
		idx++;
	}
	target[idx] = NULL;
	return (target);
}

pthread_mutex_t	*ph_allocate_fork(t_program *info, int idx, char c)
{
	if (c == 'r')
		return (info->forks[idx]);
	else
	{
		if (idx == (info->num_philos - 1))
			return (info->forks[0]);
		else
			return (info->forks[idx + 1]);
	}
}

void	ph_fork_mutex(t_philo *philo)
{
	if (!(philo->id % 2))
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->info->print_mutex);
		printf("%lu %d has taken a fork\n", ph_now_ms(philo->info), philo->id);
		pthread_mutex_unlock(philo->info->print_mutex);
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->info->print_mutex);
		printf("%lu %d has taken a fork\n", ph_now_ms(philo->info), philo->id);
		pthread_mutex_unlock(philo->info->print_mutex);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->info->print_mutex);
		printf("%lu %d has taken a fork\n", ph_now_ms(philo->info), philo->id);
		pthread_mutex_unlock(philo->info->print_mutex);
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->info->print_mutex);
		printf("%lu %d has taken a fork\n", ph_now_ms(philo->info), philo->id);
		pthread_mutex_unlock(philo->info->print_mutex);
	}
}
