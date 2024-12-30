/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_redirect_out.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:02:15 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/18 16:05:12 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_exec.h"

int	mn_redirect_out(t_redirect *now)
{
	int	out_file;

	out_file = open(now->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (out_file < 0)
	{
		mn_print_re_error(OUT_FILE, now->file);
		return (-1);
	}
	if (dup2(out_file, STDOUT_FILENO) < 0)
	{
		mn_print_re_error(DUP_FAIL, now->file);
		close(out_file);
		return (-1);
	}
	close(out_file);
	return (1);
}
