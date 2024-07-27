/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:18:06 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/27 16:31:18 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipeinfo		*info;

	if (ac == 5)
	{
		info = pi_init_info(ac, av, env);
		if (!info)
			exit(-1);
	}
	return (0);
}
