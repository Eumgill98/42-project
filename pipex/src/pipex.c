/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:18:06 by hocjeong          #+#    #+#             */
/*   Updated: 2024/08/01 16:24:59 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipeinfo		*info;
	t_file			*file;
	int				fd[2];

	if (ac == 5)
	{
		info = pi_init_info(ac, av, env);
		file = pi_init_file(ac, av);
		if (!info || !file)
			pi_exit(info, file, "info & file init fail!");
		if (pipe(fd) == -1)
			pi_exit(info, file, "pipe fail!");
		if (pi_child(info, file, fd) == -1)
			pi_exit(info, file, "command not found");
		pi_success_exit(info, file);
	}
	return (0);
}
