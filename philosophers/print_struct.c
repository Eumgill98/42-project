/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:37:36 by hocjeong          #+#    #+#             */
/*   Updated: 2024/09/23 17:37:44 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	print_info(t_program *info)
{
	printf("num_philos : %d\n", info->num_philos);
	printf("end_flag : %d\n", info->end_flag);
	printf("time_to_die : %lu\n", info->time_to_die);
	printf("time_to_eat : %lu\n", info->time_to_eat);
	printf("time_to_sleep : %lu\n", info->time_to_sleep);
}

static void	print_philo(t_philo *philo)
{
	printf("id : %d\n", philo->id);
	printf("eat_count : %d\n", philo->eat_count);
	printf("last_eaten : %lu\n", philo->last_eaten);
	printf("pthread : %p\n", (void *)philo->thread);
	printf("left_fork : %p\n", (void *)philo->left_fork);
	printf("right fork : %p\n", (void *)philo->right_fork);
	print_info(philo->info);
}

static void	print_philos(t_program *info)
{
	int	idx;

	idx = 0;
	while (idx < info->num_philos)
	{
		print_philo(info->philos[idx]);
		printf("=======================\n");
		idx++;
	}
}

