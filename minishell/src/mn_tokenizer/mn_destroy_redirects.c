/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_destroy_redirects.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:26:00 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/12 19:28:09 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

void	mn_destroy_redirects(t_redirect *head)
{
	t_redirect	*tmp;
	t_redirect	*next;

	tmp = head;
	while (tmp)
	{
		next = tmp->next;
		mn_del_redirect(tmp);
		free(tmp);
		tmp = next;
	}
}
