/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:52:28 by hocjeong          #+#    #+#             */
/*   Updated: 2024/09/24 17:10:41 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_program	t_program;
typedef struct s_philo		t_philo;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	long			last_eaten;
	pthread_t		*thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_program		*info;
}	t_philo;

typedef struct s_program
{
	int					num_philos;
	int					end_flag;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	int					end_point;
	struct timeval		start_time;
	t_philo				**philos;
	pthread_t			**pthreads;
	pthread_mutex_t		**forks;
	pthread_mutex_t		*print_mutex;
	pthread_mutex_t		*dead_mutex;
}	t_program;

int				ph_parsing(int ac, char **av, t_program *info);

long			ph_now_ms(t_program *info);

pthread_mutex_t	*ph_init_mutex(void);

int				ph_init_info(t_program *info);
t_philo			*ph_init_philo(t_program *info, int idx);
int				ph_init_philos(t_program *info);
int				ph_init_forks(t_program *info);
int				ph_init_pthreads(t_program *info);

void			ph_free_philos(t_philo **philos, int target);
void			ph_free_forks(pthread_mutex_t **forks, int target);
void			ph_free_pthreads(pthread_t **pthreads, int target);
void			ph_free_info(t_program *info);
#endif
