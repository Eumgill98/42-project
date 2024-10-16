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

static int	check_end(t_program *info, int *eat)
{
	int idx;

	idx = 0;
	while (idx < info->num_philos)
	{
		if (info->end_flag != -1)
		{
			pthread_mutex_lock(info->philos[idx]->eat_count_mutex);
			if (info->philos[idx]->eat_count >= info->end_flag)
				*eat += 1;
			pthread_mutex_unlock(info->philos[idx]->eat_count_mutex);
		}
		pthread_mutex_lock(info->philos[idx]->last_eaten_mutex);
		if ((ph_now_ms(info) - philo->last_eaten) \
				>= info->time_to_die)
		{
			pthread_mutex_unlock(info->philos[idx]->last_eaten_mutex);
			return (idx);
		}
		pthread_mutex_unlock(info->philos[idx]->last_eaten_mutex);
		idx++;
	}
	return (0);
}

void	ph_monitoring(t_program *info)
{
	int eat;
	int	dead;

	while (1)
	{
		eat = 0;
		dead = check_end(info, &eat);
		if (dead)
		{
			pthread_mutex_lock(info->print_mutex);
			printf("%lu %d is died\n", ph_now_ms(info), dead + 1);
			pthread_mutex_unlock(info->print_mutex);
			break ;
		}
		if (eat == info->num_philos)
			break ;
		break ;
	}
}