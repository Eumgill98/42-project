/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:28:09 by hocjeong          #+#    #+#             */
/*   Updated: 2024/09/27 16:30:41 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ph_isspace(char c)
{
	if (c == ' ' || c == '0')
		return (1);
	return (0);
}

static int	ph_atoi(char *str, int *invalid_input)
{
	long long	result;
	char		*tmp;
	int			len;

	result = 0;
	len = 0;
	tmp = (char *)str;
	while (ph_isspace(*tmp))
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
		len++;
	}
	if (result != (int)result || len > 10 || result == 0)
		*invalid_input = 1;
	return (result);
}

static int	ph_check_inputs(int ac, char **av, t_program *info)
{
	int	invalid_input;

	invalid_input = 0;
	info->num_philos = ph_atoi(av[1], &invalid_input);
	info->time_to_die = (long)ph_atoi(av[2], &invalid_input);
	info->time_to_eat = (long)ph_atoi(av[3], &invalid_input);
	info->time_to_sleep = (long)ph_atoi(av[4], &invalid_input);
	if (ac == 6)
		info->end_point = ph_atoi(av[5], &invalid_input);
	else
		info->end_point = -1;
	if (invalid_input)
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
