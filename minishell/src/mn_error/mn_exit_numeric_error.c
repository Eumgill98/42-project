/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_exit_numeric_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:14:46 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/16 11:31:52 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_error.h"

void	mn_exit_numeric_error(char *args)
{
	write(2, ERROR_PROMPT, ft_strlen(ERROR_PROMPT));
	write(2, "exit: ", ft_strlen("exit: "));
	write(2, args, ft_strlen(args));
	write(2, ": ", ft_strlen(": "));
	write(2, EXIT_NUMERIC_ERROR, ft_strlen(EXIT_NUMERIC_ERROR));
	write(2, "\n", 1);
	free(args);
	exit(2);
}
