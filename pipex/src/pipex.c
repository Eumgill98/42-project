/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:18:06 by hocjeong          #+#    #+#             */
/*   Updated: 2024/08/01 19:37:03 by hocjeong         ###   ########.fr       */
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
		if (pi_child(info, fd, ac, av) == -1)
			pi_exit(info, "command not found");
		pi_success_exit(info, fd);
	}
	return (0);
}
