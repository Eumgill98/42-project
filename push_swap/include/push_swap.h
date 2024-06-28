/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:45:22 by hocjeong          #+#    #+#             */
/*   Updated: 2024/06/28 21:20:41 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"

char	**ps_input(int ac, char **av);

int		check_overflow(char **s);
int		check_dup(char **s);
int		check_form(char **s);

int		ft_atoil(const char *nptr, int *overflow);

#endif
