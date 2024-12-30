/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_many_arg_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:39:52 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/16 11:28:38 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_error.h"

void	mn_many_arg_error(char *name)
{
	write(2, ERROR_PROMPT, ft_strlen(ERROR_PROMPT));
	write(2, name, ft_strlen(name));
	write(2, ": ", ft_strlen(": "));
	write(2, TOO_MANY_ARG_ERROR, ft_strlen(TOO_MANY_ARG_ERROR));
	write(2, "\n", 1);
	g_status = 1;
}
