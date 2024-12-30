/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:39:49 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/07 17:36:03 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_built_in.h"

static int	move_chdir(char *directory_path)
{
	int	flag;

	flag = chdir((const char *)directory_path);
	if (flag == -1)
	{
		write(2, ERROR_PROMPT, ft_strlen(ERROR_PROMPT));
		write(2, "cd : ", ft_strlen("cd : "));
		write(2, directory_path, ft_strlen(directory_path));
		write(2, ": ", 2);
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(2, "\n", 1);
	}
	return (flag);
}

static void	free_cd_var(char *oldpwd, char *directory_path)
{
	if (oldpwd)
		free(oldpwd);
	if (directory_path)
		free(directory_path);
	oldpwd = NULL;
	directory_path = NULL;
}

static int	check_arg(t_arg *head)
{
	if (mn_arglen(head) > 1)
	{
		mn_many_arg_error("cd");
		return (-1);
	}
	return (0);
}

int	mn_cd(t_environment *environment, t_arg *head)
{
	char	*oldpwd;
	char	*directory_path;

	if (check_arg(head) == -1)
		return (1);
	oldpwd = NULL;
	if (!head)
		directory_path = ft_strdup(getenv("HOME"));
	else
		directory_path = get_directory_path(head->arg);
	if (directory_path == NULL)
	{
		mn_print_error(MALLOC, NULL);
		return (1);
	}
	oldpwd = getcwd(oldpwd, 0);
	if (move_chdir(directory_path) == -1)
	{
		free_cd_var(oldpwd, directory_path);
		return (1);
	}
	mn_change_env_value(&(environment->envs), "OLDPWD", oldpwd, 0);
	mn_change_env_value(&(environment->exports), "OLDPWD", oldpwd, 0);
	free_cd_var(oldpwd, directory_path);
	return (0);
}
