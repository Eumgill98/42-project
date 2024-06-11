/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:44:43 by hocjeong          #+#    #+#             */
/*   Updated: 2024/06/11 18:23:26 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

#include <stdlib.h>
#include "libft.h"

typedef struct s_dlst
{
	int	element;
	s_dlst	*prev;
	s_dlst	*next;
}	t_dlst;

typedef struct s_stack
{
	int	size;
	t_dlst	*head;
	t_dlst	*tail;
}	t_stack;

#endif
