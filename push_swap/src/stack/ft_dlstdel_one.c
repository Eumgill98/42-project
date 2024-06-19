/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:21:51 by hocjeong          #+#    #+#             */
/*   Updated: 2024/06/19 17:01:14 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_dlstdel_one(t_dlst *dlst)
{
	if (dlst == NULL)
		return ;
	dlst->prev = NULL;
	dlst->next = NULL;
	dlst->element = 0;
	free(dlst);
}
