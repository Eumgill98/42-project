/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:18:06 by hocjeong          #+#    #+#             */
/*   Updated: 2024/08/03 14:58:10 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipeinfo		*info;
	int				fd[2];

	if (ac == 5)
	{
		info = pi_init_info(ac, av, env);
		if (!info)
			pi_exit(info, "info init fail!");
		if (pipe(fd) == -1)
			pi_exit(info, "pipe allocate fail!");
		info->o_fd = fd[0];
		info->c_fd = fd[1];
		if (pi_child(info, fd, ac, av) == -1)
			pi_exit(info, "command not found");
		pi_success_exit(info, fd);
	}
	else
		write(2, "wrong args\n", 11);
	return (0);
}
