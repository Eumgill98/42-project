/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:27:23 by hocjeong          #+#    #+#             */
/*   Updated: 2024/09/25 20:24:34 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ph_get_ms(void)
{
	long			sec_to_ms;
	long			usec_to_ms;
	struct timeval	now_time;

	gettimeofday(&now_time, NULL);
	sec_to_ms = 1000 * now_time.tv_sec;
	usec_to_ms = now_time.tv_usec / 1000;
	return (sec_to_ms + usec_to_ms);
}

long	ph_now_ms(t_program *info)
{
	long	now_ms;

	now_ms = ph_get_ms();
	return (now_ms - info->start_time);
}
