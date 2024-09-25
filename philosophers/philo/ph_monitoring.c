/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:04:57 by hocjeong          #+#    #+#             */
/*   Updated: 2024/09/25 21:36:29 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_dead(t_philo *philo)
{
	if (philo->eat_count == philo->info->end_point)
		return (2);
	if ((ph_now_ms(philo->info) - philo->last_eaten) \
			>= philo->info->time_to_die)
		return (1);
	return (0);
}

static int	check_flag(t_philo *philo)
{
	int	type;

	type = check_dead(philo);
	if (type)
	{
		pthread_mutex_lock(philo->info->dead_mutex);
		philo->info->end_flag = 1;
		pthread_mutex_unlock(philo->info->dead_mutex);
		return (type);
	}
	return (0);
}

void	ph_monitoring(t_program *info)
{
	int	idx;
	int	died_id;
	int	flag;

	flag = 0;
	while (1)
	{
		if (flag)
		{
			if (flag == 1)
				printf("%lu %d is died\n", ph_now_ms(info), died_id + 1);
			break ;
		}
		idx = 0;
		while (idx < info->num_philos)
		{
			flag = check_flag(info->philos[idx]);
			if (flag)
			{
				died_id = idx;
				break ;
			}
			idx++;
		}
	}
}
