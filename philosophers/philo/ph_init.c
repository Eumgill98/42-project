/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:36:01 by hocjeong          #+#    #+#             */
/*   Updated: 2024/09/24 19:07:28 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_init_info(t_program *info)
{
	info->num_philos = 0;
	info->end_flag = 0;
	info->time_to_die = 0;
	info->time_to_eat = 0;
	info->time_to_sleep = 0;
	info->end_point = -1;
	gettimeofday(&(info->start_time), NULL);
	info->philos = NULL;
	info->forks = NULL;
	info->pthreads = NULL;
	info->print_mutex = ph_init_mutex();
	info->dead_mutex = ph_init_mutex();
	if (info->print_mutex == NULL || info->dead_mutex == NULL)
		return (-1);
	return (0);
}

t_philo	*ph_init_philo(t_program *info, int idx)
{
	t_philo	*new;
	int		left_fork;
	int		right_fork;

	if (idx == 0)
		right_fork = (info->num_philos) - 1;
	else
		right_fork = idx - 1;
	if (idx == (info->num_philos - 1))
		left_fork = 0;
	else
		right_fork = idx + 1;
	new = (t_philo *)malloc(sizeof(t_philo));
	if (new == NULL)
		return (NULL);
	new->id = idx;
	new->eat_count = 0;
	new->last_eaten = 0;
	new->thread = info->pthreads[idx];
	new->left_fork = (info->forks)[left_fork];
	new->right_fork = (info->forks)[right_fork];
	new->info = info;
	return (new);
}

int	ph_init_forks(t_program *info)
{
	int				idx;
	pthread_mutex_t	*tmp;

	info->forks = (pthread_mutex_t **)malloc(sizeof(pthread_mutex_t *) \
				* (info->num_philos + 1));
	if (info->forks == NULL)
		return (-1);
	idx = 0;
	while (idx < info->num_philos)
	{
		tmp = ph_init_mutex();
		if (tmp == NULL)
		{
			ph_free_forks(info->forks, idx);
			info->forks = NULL;
			return (-1);
		}
		info->forks[idx] = tmp;
		idx++;
	}
	info->forks[idx] = NULL;
	return (0);
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
