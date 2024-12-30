/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_new_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:35:00 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/12 19:39:51 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

t_arg	*mn_new_arg(char *arg)
{
	t_arg	*new;

	new = (t_arg *)malloc(sizeof(t_arg));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->arg = ft_strdup(arg);
	if (new->arg == NULL)
	{
		free(new);
		return (NULL);
	}
	return (new);
}
