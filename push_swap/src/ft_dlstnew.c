/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:15:52 by hocjeong          #+#    #+#             */
/*   Updated: 2024/06/11 20:01:04 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_dlst	*ft_dlstnew(char c)
{
	t_dlst	*new;

	new = (t_dlst *)malloc(sizeof(t_dlst);
	if (!new)
		return NULL;
	new -> prev = 0;
	new -> next = 0;
	new -> element = ft_atoi(c);
	return (new);
}
