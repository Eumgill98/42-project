/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_print_re_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:51:26 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/24 18:40:20 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_error.h"

void	mn_print_re_error(t_re_error_type error_type, char *name)
{
	if (error_type == OPEN_FILE)
		mn_open_error(name);
	else if (error_type == OUT_FILE)
		mn_out_error(name);
	else if (error_type == CANT_FILE)
		mn_cant_error(name);
	else if (error_type == DUP_FAIL)
		mn_dup2_error(name);
}
