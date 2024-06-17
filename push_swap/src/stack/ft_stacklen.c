/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacklen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:09:58 by hocjeong          #+#    #+#             */
/*   Updated: 2024/06/17 15:43:30 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"

size_t	ft_stacklen(char **s)
{
	size_t	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}
