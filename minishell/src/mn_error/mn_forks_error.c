/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_forks_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:34:49 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/21 10:35:04 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_error.h"

void	mn_forks_error(char *name)
{
	write(2, ERROR_PROMPT, ft_strlen(ERROR_PROMPT));
	write(2, "'", 1);
	write(2, name, ft_strlen(name));
	write(2, "'", 1);
	write(2, ": ", ft_strlen(": "));
	write(2, FORK_ERROR, ft_strlen(FORK_ERROR));
	write(2, "\n", 1);
}
