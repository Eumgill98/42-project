/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:58:20 by hocjeong          #+#    #+#             */
/*   Updated: 2024/03/07 16:32:54 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tmp;
	size_t	total_size;

	total_size = nmemb * size;
	if (!total_size)
		return (malloc(0));
	if ((total_size / nmemb) != size)
		return (0);
	tmp = malloc(total_size);
	if (!tmp)
		return (0);
	ft_bzero(tmp, (total_size));
	return (tmp);
}
