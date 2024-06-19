/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:44:43 by hocjeong          #+#    #+#             */
/*   Updated: 2024/06/19 17:44:21 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include "libft.h"

typedef struct s_dlst
{
	int				element;
	struct s_dlst	*prev;
	struct s_dlst	*next;
}	t_dlst;

typedef struct s_stack
{
	size_t	size;
	t_dlst	*head;
	t_dlst	*tail;
}	t_stack;

t_stack	*ft_stackinit(void);
int		ft_stackmake(t_stack *stack, char **s);

size_t	ft_stacklen(char **s);

t_dlst	*ft_dlstnew(int data);
void	ft_dlstdel_one(t_dlst *dlst);
int		ft_dlstadd_back(t_stack *stack, int data);
int		ft_dlstadd_front(t_stack *stack, int data);
int		ft_dlstpop_back(t_stack *stack);
int		ft_dlstpop_front(t_stack *stack);
void	ft_dlstpop_all(t_stack *stack);

int		ft_swap(t_stack *stack);
int		ft_push(t_stack *on_stack, t_stack *to_stack);
int		ft_rotate(t_stack *stack);
int		ft_rrotate(t_stack *stack);

#endif
