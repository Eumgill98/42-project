/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:03:14 by hocjeong          #+#    #+#             */
/*   Updated: 2024/06/19 17:06:06 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_dlst	*ft_dlstnew(int data)
{
	t_dlst	*new;

	new = (t_dlst *)malloc(sizeof(t_dlst));
	if (!new)
		return (NULL);
	new->element = data;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
