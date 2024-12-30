/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:15:34 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/05 16:19:24 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_built_in.h"

static int	check_flag(t_arg *args)
{
	t_arg	*tmp;

	tmp = args;
	if (ft_strcmp(tmp->arg, "-n") == 0)
		return (1);
	return (0);
}

static char	*joined_args(t_arg *args)
{
	t_arg	*tmp;
	char	*join_str;
	char	*backup;

	tmp = args;
	join_str = ft_strdup("");
	while (tmp)
	{
		backup = join_str;
		join_str = ft_strjoin(join_str, tmp->arg);
		free(backup);
		if (join_str == NULL)
			return (NULL);
		if (tmp->next)
		{
			backup = join_str;
			join_str = ft_strjoin(join_str, " ");
			free(backup);
			if (join_str == NULL)
				return (NULL);
		}
		tmp = tmp->next;
	}
	return (join_str);
}

int	mn_echo(t_arg *head)
{
	t_arg	*tmp;
	char	*join_str;
	int		flag;

	join_str = NULL;
	tmp = head;
	flag = 0;
	if (tmp && check_flag(tmp) == 1)
	{
		flag = 1;
		tmp = tmp->next;
	}
	join_str = joined_args(tmp);
	if (join_str == NULL)
	{
		mn_print_error(MALLOC, NULL);
		return (1);
	}
	printf("%s", join_str);
	free(join_str);
	if (flag == 0)
		printf("\n");
	return (0);
}
