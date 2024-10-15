/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:45:59 by hocjeong          #+#    #+#             */
/*   Updated: 2024/10/14 17:07:06 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ph_eat(t_philo *philo)
{
	if (philo->info->num_philos == 1)
		ph_fork_mutex_one(philo);
	else
		ph_fork_mutex(philo);
	pthread_mutex_lock(philo->last_eaten_mutex);
	philo->last_eaten = ph_now_ms(philo->info);
	pthread_mutex_unlock(philo->last_eaten_mutex);
	ph_print(philo->id, 'e', philo->info);
	ph_new_sleep(philo->info->time_to_eat);
	pthread_mutex_lock(philo->eat_count_mutex);
	philo->eat_count += 1;
	pthread_mutex_unlock(philo->eat_count_mutex);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void	ph_sleep(t_philo *philo)
{
	ph_print(philo->id, 's', philo->info);
	ph_new_sleep(philo->info->time_to_sleep);
}

static void	ph_think(t_philo *philo)
{
	ph_print(philo->id, 't', philo->info);
}

void	*ph_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (1)
	{
		ph_eat(philo);
		ph_sleep(philo);
		ph_think(philo);
		pthread_mutex_lock(philo->info->dead_mutex);
		if (philo->info->end_flag)
		{
			pthread_mutex_unlock(philo->info->dead_mutex);
			break ;
		}
		pthread_mutex_unlock(philo->info->dead_mutex);
	}
	return (NULL);
}
