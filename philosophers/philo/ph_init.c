/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:36:01 by hocjeong          #+#    #+#             */
/*   Updated: 2024/09/26 16:55:58 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_init_info(t_program *info)
{
	info->num_philos = 0;
	info->end_flag = 0;
	info->all_thread_end = 0;
	info->time_to_die = 0;
	info->time_to_eat = 0;
	info->time_to_sleep = 0;
	info->end_point = -1;
	info->start_time = 0;
	info->philos = NULL;
	info->forks = NULL;
	info->last_eaten_mutexs = NULL;
	info->eat_count_mutexs = NULL;
	info->pthreads = NULL;
	info->print_mutex = NULL;
	info->dead_mutex = NULL;
	info->end_mutex = NULL;
}

t_philo	*ph_init_philo(t_program *info, int idx)
{
	t_philo	*new;

	new = (t_philo *)malloc(sizeof(t_philo));
	if (new == NULL)
		return (NULL);
	new->id = idx + 1;
	new->eat_count = 0;
	new->thread_end = 0;
	new->last_eaten = 0;
	new->thread = info->pthreads[idx];
	new->last_eaten_mutex = info->last_eaten_mutexs[idx];
	new->eat_count_mutex = info->eat_count_mutexs[idx];
	new->left_fork = ph_allocate_fork(info, idx, 'l');
	new->right_fork = ph_allocate_fork(info, idx, 'r');
	new->info = info;
	return (new);
}

int	ph_init_pthreads(t_program *info)
{
	int			idx;
	pthread_t	*tmp;

	info->pthreads = (pthread_t **)malloc(sizeof(pthread_t *) \
						* (info->num_philos + 1));
	if (info->pthreads == NULL)
		return (-1);
	idx = 0;
	while (idx < info->num_philos)
	{
		tmp = (pthread_t *)malloc(sizeof(pthread_t));
		if (!tmp)
		{
			ph_free_pthreads(info->pthreads, idx);
			info->pthreads = NULL;
			return (-1);
		}
		info->pthreads[idx] = tmp;
		idx++;
	}
	info->pthreads[idx] = NULL;
	return (0);
}

int	ph_init_info_mutexs(t_program *info)
{
	info->forks = ph_malloc_dmutex(info->num_philos);
	info->last_eaten_mutexs = ph_malloc_dmutex(info->num_philos);
	info->eat_count_mutexs = ph_malloc_dmutex(info->num_philos);
	info->print_mutex = ph_malloc_mutex();
	info->dead_mutex = ph_malloc_mutex();
	info->end_mutex = ph_malloc_mutex();
	if (!(info->forks) || !(info->last_eaten_mutexs) || \
		!(info->eat_count_mutexs) || !(info->print_mutex) || \
		!(info->dead_mutex) || !(info->end_mutex))
		return (-1);
	return (0);
}

int	ph_init_philos(t_program *info)
{
	int		idx;
	t_philo	*tmp;

	info->philos = (t_philo **)malloc(sizeof(t_philo *) \
					* (info->num_philos + 1));
	if (info->philos == NULL)
		return (-1);
	idx = 0;
	while (idx < info->num_philos)
	{
		tmp = ph_init_philo(info, idx);
		if (tmp == NULL)
		{
			ph_free_philos(info->philos, idx);
			info->philos = NULL;
			return (-1);
		}
		info->philos[idx] = tmp;
		idx++;
	}
	info->philos[idx] = NULL;
	return (0);
}
