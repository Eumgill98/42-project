/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:35:46 by hocjeong          #+#    #+#             */
/*   Updated: 2024/10/04 20:16:22 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ph_make_philo(t_philo *philo)
{
	int	pthread_id;

	pthread_id = pthread_create(philo->thread, NULL, ph_routine, (void *)philo);
	if (pthread_id < 0)
		return (-1);
	return (0);
}

void	ph_philo(t_program *info)
{
	int	idx;

	idx = 0;
	info->start_time = ph_get_ms();
	while (idx < info->num_philos)
	{
		if (ph_make_philo(info->philos[idx]) == -1)
			return ;
		idx++;
	}
}
