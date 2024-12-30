/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_redirect_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:34:32 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/18 16:13:12 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_exec.h"

int	mn_redirect_in(t_redirect *now)
{
	int	in_file;

	in_file = open(now->file, O_RDONLY);
	if (in_file < 0)
	{
		if (errno == 2)
			mn_print_re_error(OPEN_FILE, now->file);
		else
			mn_print_re_error(CANT_FILE, now->file);
		return (-1);
	}
	if (dup2(in_file, STDIN_FILENO) < 0)
	{
		mn_print_re_error(DUP_FAIL, now->file);
		close(in_file);
		return (-1);
	}
	close(in_file);
	return (1);
}
