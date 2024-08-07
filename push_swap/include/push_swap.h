/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:45:22 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/15 15:05:17 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"
# include <unistd.h>

typedef struct s_ps_stacks
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_ps_stacks;

t_ps_stacks	*ps_init_stacks(void);

int			ps_input(int ac, char **av, t_ps_stacks *stacks);
int			check_overflow(char **s);
int			check_dup(t_stack *stack);
int			check_form(char **s);

int			ft_atoil(const char *nptr, int *overflow);

void		ps_free_stacks(t_ps_stacks *stacks);
void		ps_free_input(char **s);

int			ps_encoding(const char *command);
int			ps_functions(t_ps_stacks *stacks, const char *command, int flag);

int			ps_sort_check(t_stack *stack);
int			ps_rsort_check(t_stack *stack);
int			ps_sort(t_ps_stacks *stack);
int			ps_make_idx(t_stack *stack);

int			ps_check_case(t_dlst *head);
int			ps_max_idx(t_ps_stacks *stacks);
int			ps_min_idx(t_ps_stacks *stacks);
int			ps_pb_idx(t_ps_stacks *stacks, int idx, int size);
void		ps_sort_big(t_ps_stacks *stacks);
void		ps_sort_small(t_ps_stacks *stacks);

void		ps_printstr(const char *s);
void		ps_exit(void);

#endif
