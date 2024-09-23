/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:36:01 by hocjeong          #+#    #+#             */
/*   Updated: 2024/09/23 17:26:37 by hocjeong         ###   ########.fr       */
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
	info->print_mutex = ph_init_mutex();
	info->dead_mutex = ph_init_mutex();
	if (info->print_mutex == NULL || info->dead_mutex == NULL)
		return (-1);
	return (0);
}

t_philo	*ph_init_philo(t_program *info, int idx)
{
	t_philo	*new;

	new = (t_philo *)malloc(sizeof(t_philo));
	if (new == NULL)
		return (NULL);
	new->id = idx;
	new->eat_count = 0;
	new->last_eaten = 0;
	new->thread = NULL;
	new->left_fork = NULL;
	new->right_fork = NULL;
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
