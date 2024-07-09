/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:45:22 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/04 18:30:41 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"

typedef struct s_ps_stacks
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_ps_stacks;

t_ps_stacks	*ps_init_stacks(char **inputs);
char		**ps_input(int ac, char **av);

int			check_overflow(char **s);
int			check_dup(char **s);
int			check_form(char **s);

int			ft_atoil(const char *nptr, int *overflow);

void		ps_free_stacks(t_ps_stacks *stacks);
void		ps_free_input(char **s);

int			ps_encoding(const char *command);
int 		ps_functions(t_ps_stacks *stacks, const char *command);

#endif