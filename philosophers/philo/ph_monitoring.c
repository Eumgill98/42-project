/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:04:57 by hocjeong          #+#    #+#             */
/*   Updated: 2024/10/02 17:22:51 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_all_eaten(t_program *info)
{
	int		idx;
	int		enough_eat;
	t_philo	*philo;

	idx = 0;
	enough_eat = 0;
	while (idx < info->num_philos)
	{
		philo = info->philos[idx];
		pthread_mutex_lock(philo->eat_count_mutex);
		if (philo->eat_count >= info->end_point)
			enough_eat += 1;
		pthread_mutex_unlock(philo->eat_count_mutex);
		idx++;
	}
	if (enough_eat == info->num_philos)
	{
		pthread_mutex_lock(info->dead_mutex);
		info->end_flag = 1;
		pthread_mutex_unlock(info->dead_mutex);
		return (1);
	}
	return (0);
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
			pthread_mutex_lock(info->print_mutex);
			pthread_mutex_lock(info->dead_mutex);
			info->end_flag = 1;
			printf("%lu %d is died\n", ph_now_ms(info), idx + 1);
			pthread_mutex_unlock(info->print_mutex);
			pthread_mutex_unlock(philo->last_eaten_mutex);
			pthread_mutex_unlock(info->dead_mutex);
			return (1);
		}
		pthread_mutex_unlock(philo->last_eaten_mutex);
		idx++;
	}
	return (0);
}

void	ph_monitoring(t_program *info)
{
	int	all_eat_flag;
	int	dead_flag;

	while (1)
	{
		if (info->end_point != -1)
		{
			all_eat_flag = check_all_eaten(info);
			dead_flag = check_dead(info);
			if (all_eat_flag || dead_flag)
				break ;
		}
		else
		{
			dead_flag = check_dead(info);
			if (dead_flag)
				break ;
		}
	}
}

void	ph_pthread_dead(t_program *info)
{
	int		idx;
	int		dead_pthread;
	t_philo	*philo;

	while (1)
	{
		idx = 0;
		dead_pthread = 0;
		while (idx < info->num_philos)
		{
			philo = info->philos[idx];
			pthread_mutex_lock(philo->thread_end_mutex);
			if (philo->thread_end)
				dead_pthread++;
			pthread_mutex_unlock(philo->thread_end_mutex);
			idx++;
		}
		if (dead_pthread == info->num_philos)
			break ;
	}
}
