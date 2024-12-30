/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_del_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:22:14 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/12 19:42:54 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

void	mn_del_redirect(t_redirect *redirect)
{
	if (redirect == NULL)
		return ;
	if (redirect->file)
		free(redirect->file);
	if (redirect->heredoc_fd > 0)
		close(redirect->heredoc_fd);
	redirect->file = NULL;
	redirect->heredoc_fd = 0;
}
