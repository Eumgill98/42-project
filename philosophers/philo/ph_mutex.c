/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_mutex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:20:06 by hocjeong          #+#    #+#             */
/*   Updated: 2024/09/25 20:58:31 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*ph_init_mutex(void)
{
	pthread_mutex_t	*new;

	new = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (new == NULL)
		return (NULL);
	if (pthread_mutex_init(new, NULL) == 0)
		return (new);
	return (NULL);
}

void	ph_fork_mutex(t_philo *philo)
{
	if (!(philo->id % 2))
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->info->print_mutex);
		printf("%lu %d has taken a fork\n", ph_now_ms(philo->info), philo->id);
		pthread_mutex_unlock(philo->info->print_mutex);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->info->print_mutex);
		printf("%lu %d has taken a fork\n", ph_now_ms(philo->info), philo->id);
		pthread_mutex_unlock(philo->info->print_mutex);
	}
}
