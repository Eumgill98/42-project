/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:15:16 by hocjeong          #+#    #+#             */
/*   Updated: 2024/09/23 17:39:05 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_program	info;

	if (ph_init_info(&info) == -1 || ph_parsing(ac, av, &info) == -1)
		ph_free_info(&info);
	if (ph_init_forks(&info) == -1 || ph_init_philos(&info) == -1)
		ph_free_info(&info);
	// TODO 1. id 삽입 및 포크 삽입
	// TODO 2. Routine 
	// TODO 3. 모니터링 및 종료
	ph_free_info(&info);
}
