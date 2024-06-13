/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:44:43 by hocjeong          #+#    #+#             */
/*   Updated: 2024/06/13 20:53:25 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include "libft.h"

typedef struct s_dlst
{
	int		element;
	s_dlst	*prev;
	s_dlst	*next;
}	t_dlst;

typedef struct s_stack
{
	int		size;
	t_dlst	*head;
	t_dlst	*tail;
}	t_stack;

t_stack	*ft_stackinit(void);
void	ft_stackmake(t_stack *stack, char **s);

int		ft_stacklen(char **s);

t_dlst	*ft_dlstnew(char data);
int		ft_dlstadd_back(t_stack *stack, char data);
int		ft_dlstadd_front(t_stack *stack, char data);
#endif
