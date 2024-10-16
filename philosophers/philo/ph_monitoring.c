/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:04:57 by hocjeong          #+#    #+#             */
/*   Updated: 2024/10/16 16:08:47 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_all_eaten(t_program *info)
{
	int		idx;
	t_philo	*philo;

	idx = 0;
	while (idx < info->num_philos)
	{
		philo = info->philos[idx];
		pthread_mutex_lock(philo->eat_count_mutex);
		if (philo->eat_count < info->end_point)
		{
			pthread_mutex_unlock(philo->eat_count_mutex);
			return (0);
		}
		pthread_mutex_unlock(philo->eat_count_mutex);
		idx++;
	}
	pthread_mutex_lock(info->dead_mutex);
	info->end_flag = 1;
	pthread_mutex_unlock(info->dead_mutex);
	return (1);
}

static int	check_dead(t_program *info)
{
	int		idx;
	t_philo	*philo;

	idx = 0;
	while (idx < info->num_philos)
	{
		philo = info->philos[idx];
		pthread_mutex_lock(philo->last_eaten_mutex);
		if ((ph_now_ms(info) - philo->last_eaten) \
				>= info->time_to_die)
		{
			pthread_mutex_unlock(philo->last_eaten_mutex);
			break ;
		}
		pthread_mutex_unlock(philo->last_eaten_mutex);
		idx++;
		usleep(100);
	}
	if (idx < info->num_philos)
	{
		pthread_mutex_lock(info->dead_mutex);
		pthread_mutex_lock(info->print_mutex);
		info->end_flag = 1;
		printf("%lu %d is died\n", ph_now_ms(info), idx + 1);
		pthread_mutex_unlock(info->print_mutex);
		pthread_mutex_unlock(info->dead_mutex);
		return (1);
	}
	return (0);
}

void	ph_monitoring(t_program *info)
{
	while (1)
	{
		if (check_dead(info))
			break ;
		if (info->end_point != -1)
		{
			if (check_all_eaten(info))
				break ;
		}
		usleep(100);
	}
}
