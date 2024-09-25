/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:45:59 by hocjeong          #+#    #+#             */
/*   Updated: 2024/09/25 20:45:33 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ph_eat(t_philo *philo)
{
	ph_fork_mutex(philo);
	philo->last_eaten = ph_now_ms(philo->info);
	if (philo->info->print_mutex != NULL)
	{
		pthread_mutex_lock(philo->info->print_mutex);
		printf("%lu %d is eating\n", ph_now_ms(philo->info), philo->id);
		pthread_mutex_unlock(philo->info->print_mutex);
	}
	ph_new_sleep(philo->info->time_to_sleep);
	philo->eat_count += 1;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void	ph_sleep(t_philo *philo)
{
	if (philo->info->print_mutex != NULL)
	{
		pthread_mutex_lock(philo->info->print_mutex);
		printf("%lu %d is sleeping\n", ph_now_ms(philo->info), philo->id);
		pthread_mutex_unlock(philo->info->print_mutex);
	}
	ph_new_sleep(philo->info->time_to_sleep);
}

static void	ph_think(t_philo *philo)
{
	if (philo->info->print_mutex != NULL)
	{
		pthread_mutex_lock(philo->info->print_mutex);
		printf("%lu %d is thinking\n", ph_now_ms(philo->info), philo->id);
		pthread_mutex_unlock(philo->info->print_mutex);
	}
}

void	*ph_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (1)
	{
		if (philo->info->end_flag)
			break ;
		ph_eat(philo);
		ph_sleep(philo);
		ph_think(philo);
	}
	return (NULL);
}
