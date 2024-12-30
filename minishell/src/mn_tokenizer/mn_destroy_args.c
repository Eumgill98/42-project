/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_destroy_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:44:09 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/12 19:45:27 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

void	mn_destroy_args(t_arg *head)
{
	t_arg	*tmp;
	t_arg	*next;

	tmp = head;
	while (tmp)
	{
		next = tmp->next;
		mn_del_arg(tmp);
		free(tmp);
		tmp = next;
	}
}
