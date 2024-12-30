/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:14:04 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/08 21:25:39 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_built_in.h"

static void	skip_space_check_sign(char *argv, int *i, int *sign)
{
	while (argv[*i] && argv[*i] == ' ')
		(*i)++;
	if (argv[*i] == '-' || argv[*i] == '+')
	{
		if (argv[*i] == '-')
			*sign = -1;
		(*i)++;
	}
}

static long long	ft_atoll(char *argv, int *flag)
{
	long long	result;
	long long	prev;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	skip_space_check_sign(argv, &i, &sign);
	while (argv[i] >= '0' && argv[i] <= '9')
	{
		prev = result;
		result = (result * 10) + (argv[i] - '0');
		if (prev != (result - (argv[i] - '0')) / 10)
		{
			*flag = 1;
			return (0);
		}
		i++;
	}
	if (argv[i] != '\0')
		*flag = 1;
	return (result * sign);
}

static int	check_exit_status(t_arg *head, t_mn_setting *setting)
{
	char			*arg;
	int				flag;
	long long		num;
	unsigned char	exit_status;	

	if (head == NULL)
		return (0);
	if (mn_arglen(head) > 1)
	{
		mn_many_arg_error("exit");
		return (-1);
	}
	flag = 0;
	arg = ft_strdup(head->arg);
	mn_setting_free(setting);
	if (setting)
		free(setting);
	num = ft_atoll(arg, &flag);
	exit_status = (unsigned char)num;
	if (flag == 1)
		mn_exit_numeric_error(arg);
	free(arg);
	return (exit_status);
}

int	mn_exit(t_mn_setting *setting, t_arg *head)
{
	unsigned char	exit_status;
	int				status;

	printf("exit\n");
	status = check_exit_status(head, setting);
	if (status == -1)
		return (1);
	exit_status = (unsigned char)status;
	exit(exit_status);
}
