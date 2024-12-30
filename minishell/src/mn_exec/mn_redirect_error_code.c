/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_redirect_error_code.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:33:19 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/21 16:35:28 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_exec.h"

int	mn_redirect_error_code(t_files files)
{
	if (files.in_file < 0)
		return (-1 * files.in_file);
	if (files.out_file < 0)
		return (-1 * files.out_file);
	return (-1);
}
