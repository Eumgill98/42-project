/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:52:28 by hocjeong          #+#    #+#             */
/*   Updated: 2024/09/12 17:38:43 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				dead;
	int				eat_count;
	long			last_eaten;
	pthread_t		*thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

typedef struct s_program
{
	int					num_philos;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	int					end_point;
	struct timeval		start_time;
	t_philo				*philos;
}	t_program;

int		ph_parsing(int ac, char **av, t_program *info);
long	ph_now_ms(t_program *info);
void	ph_init_info(t_program *info);

#endif
