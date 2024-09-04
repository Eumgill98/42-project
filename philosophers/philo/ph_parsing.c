/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:28:09 by hocjeong          #+#    #+#             */
/*   Updated: 2024/09/04 18:01:09 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ph_atoi(char *str, int *overflow, int *invalid_input)
{
	long long	result;
	char		*tmp;

	result = 0;
	tmp = (char *)str;
	while (*tmp == ' ')
		tmp++;
	while (*tmp)
	{
		if (!(*tmp >= '0' && *tmp <= '9'))
		{
			*invalid_input = 1;
			return (-1);
		}
		result *= 10;
		result += (*tmp - '0');
		tmp++;
	}
	if (result != (int)result)
		*overflow = 1;
	return (result);
}

static int	ph_check_inputs(int ac, char **av, t_program *info)
{
	int	overflow;
	int	invalid_input;

	overflow = 0;
	invalid_input = 0;
	info->num_philos = ph_atoi(av[1], &overflow, &invalid_input);
	info->time_to_die = ph_atoi(av[2], &overflow, &invalid_input);
	info->time_to_eat = ph_atoi(av[3], &overflow, &invalid_input);
	info->time_to_sleep = ph_atoi(av[4], &overflow, &invalid_input);
	if (ac == 6)
		info->end_point = ph_atoi(av[5], &overflow, &invalid_input);
	else
		info->end_point = 0;
	if (overflow || invalid_input)
		return (-1);
	return (0);
}

int	ph_parsing(int ac, char **av, t_program *info)
{
	if (ac == 5 || ac == 6)
		return (ph_check_inputs(ac, av, info));
	else
		return (-1);
	return (0);
}
