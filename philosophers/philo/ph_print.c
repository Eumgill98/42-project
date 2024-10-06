/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:57:48 by hocjeong          #+#    #+#             */
/*   Updated: 2024/10/06 16:06:56 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_print(int id, char type, t_program *info)
{
	pthread_mutex_lock(info->dead_mutex);
	if (!info->end_flag)
	{
		pthread_mutex_lock(info->print_mutex);
		if (type == 'f')
			printf("%lu %d has taken a fork\n", ph_now_ms(info), id);
		else if (type == 'e')
			printf("%lu %d is eating\n", ph_now_ms(info), id);
		else if (type == 's')
			printf("%lu %d is sleeping\n", ph_now_ms(info), id);
		else if (type == 't')
			printf("%lu %d is thinking\n", ph_now_ms(info), id);
		pthread_mutex_unlock(info->print_mutex);
	}
	pthread_mutex_unlock(info->dead_mutex);
}
