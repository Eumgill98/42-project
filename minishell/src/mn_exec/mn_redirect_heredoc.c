/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_redirect_heredoc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:24:14 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/28 18:40:39 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_exec.h"

int	mn_redirect_heredoc(t_redirect *now)
{
	if (dup2(now->heredoc_fd, STDIN_FILENO) < 0)
	{
		mn_print_re_error(DUP_FAIL, "HEREDOC_FD");
		close(now->heredoc_fd);
		now->heredoc_fd = 0;
		return (-1);
	}
	close(now->heredoc_fd);
	now->heredoc_fd = 0;
	return (0);
}
