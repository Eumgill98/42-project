/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_mutex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:20:06 by hocjeong          #+#    #+#             */
/*   Updated: 2024/09/23 16:36:29 by hocjeong         ###   ########.fr       */
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
