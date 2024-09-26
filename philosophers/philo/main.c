/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:15:16 by hocjeong          #+#    #+#             */
/*   Updated: 2024/09/25 21:45:43 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_pthread_exit(t_program *info)
{
	int	total_end_pthread;
	int	idx;

	while (1)
	{
		total_end_pthread = 0;
		idx = 0;
		while (idx < info->num_philos)
		{
			pthread_mutex_lock(info->end_mutex);
			total_end_pthread += info->philos[idx]->thread_end;
			pthread_mutex_unlock(info->end_mutex);
			idx++;
		}
		if (total_end_pthread == num_philos)
			break ;
	}
}

int	main(int ac, char **av)
{
	t_program	info;

	if (ph_init_info(&info) == -1 || ph_parsing(ac, av, &info) == -1)
	{
		ph_free_info(&info);
		return (-1);
	}
	if (ph_init_forks(&info) == -1 || ph_init_pthreads(&info) == -1 \
			|| ph_init_philos(&info) == -1)
	{
		ph_free_info(&info);
		return (-1);
	}
	ph_philo(&info);
	ph_monitoring(&info);
	ph_pthread_exit(&info);
	ph_free_info(&info);
}
