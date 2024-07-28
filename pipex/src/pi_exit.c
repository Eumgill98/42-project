/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:52:41 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/27 15:52:43 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pi_error(char *msg)
{
	perror(msg)
	return (EXIT_FAILURE);
}

void	pi_exit(t_pipeinfo *info, t_file *file, char *msg)
{
	pi_freeinfo(info);
	pi_freefile(file);
	exit(pi_error(msg));
}
