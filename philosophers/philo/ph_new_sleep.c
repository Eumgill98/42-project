/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_new_sleep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:52:29 by hocjeong          #+#    #+#             */
/*   Updated: 2024/10/02 15:40:08 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_new_sleep(long ms)
{
	long	start_ms;
	long	now_ms;

	start_ms = ph_get_ms();
	usleep(ms * 500);
	while (1)
	{
		usleep(100);
		now_ms = ph_get_ms();
		if (now_ms >= start_ms + ms)
			break ;
	}
}
