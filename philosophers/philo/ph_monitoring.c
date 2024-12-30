/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:04:57 by hocjeong          #+#    #+#             */
/*   Updated: 2024/10/16 18:25:04 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_end(t_program *info, int *eat, int *dead, int *dead_idx)
{
	int	idx;

	idx = 0;
	while (idx < info->num_philos)
	{
		if (info->end_point != -1)
		{
			pthread_mutex_lock(info->philos[idx]->eat_count_mutex);
			if (info->philos[idx]->eat_count >= info->end_point)
				*eat += 1;
			pthread_mutex_unlock(info->philos[idx]->eat_count_mutex);
		}
		pthread_mutex_lock(info->philos[idx]->last_eaten_mutex);
		if ((ph_now_ms(info) - info->philos[idx]->last_eaten) \
				>= info->time_to_die)
		{
			pthread_mutex_unlock(info->philos[idx]->last_eaten_mutex);
			*dead_idx = idx;
			*dead = 1;
			return ;
		}
		pthread_mutex_unlock(info->philos[idx]->last_eaten_mutex);
		idx++;
		usleep(100);
	}
}

static int	end_loops(t_program *info, int eat, int dead, int dead_idx)
{
	if (dead)
	{
		pthread_mutex_lock(info->dead_mutex);
		pthread_mutex_lock(info->print_mutex);
		info->end_flag = 1;
		printf("%lu %d is died\n", ph_now_ms(info), dead_idx + 1);
		pthread_mutex_unlock(info->print_mutex);
		pthread_mutex_unlock(info->dead_mutex);
		return (1);
	}
	if (eat == info->num_philos)
	{
		pthread_mutex_lock(info->dead_mutex);
		info->end_flag = 1;
		pthread_mutex_unlock(info->dead_mutex);
		return (1);
	}
	return (0);
}

void	ph_monitoring(t_program *info)
{
	int	eat;
	int	dead;
	int	dead_idx;

	while (1)
	{
		eat = 0;
		dead_idx = 0;
		dead = 0;
		check_end(info, &eat, &dead, &dead_idx);
		if (end_loops(info, eat, dead, dead_idx))
			break ;
		usleep(100);
	}
}
