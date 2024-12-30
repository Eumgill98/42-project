/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:08:03 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/21 09:13:24 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_exec.h"

static int	check_stop(t_files files)
{
	if (files.in_file < 0 || files.out_file < 0)
		return (-1);
	return (0);
}

t_files	mn_redirect(t_redirect *redirects)
{
	t_files		files;
	t_redirect	*tmp;

	tmp = redirects;
	files.in_file = 0;
	files.out_file = 0;
	while (tmp)
	{
		if (tmp->redirect_type == IN)
			files.in_file = mn_redirect_in(tmp);
		else if (tmp->redirect_type == HEREDOC)
			files.in_file = mn_redirect_heredoc(tmp);
		else if (tmp->redirect_type == APPEND)
			files.out_file = mn_redirect_append(tmp);
		else if (tmp->redirect_type == OUT)
			files.out_file = mn_redirect_out(tmp);
		if (check_stop(files) == -1)
			return (files);
		tmp = tmp->next;
	}
	return (files);
}
