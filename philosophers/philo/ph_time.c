/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:27:23 by hocjeong          #+#    #+#             */
/*   Updated: 2024/09/12 17:31:26 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ph_now_ms(t_program *info)
{
	long			start_ms;
	struct timeval	now_time;

	start_ms = info->start_time.tv_usec;
	gettimeofday(&now_time, NULL);
	return (now_time.tv_usec - start_ms);
}
