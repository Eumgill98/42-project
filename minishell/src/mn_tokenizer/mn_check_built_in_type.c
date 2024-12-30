/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_check_built_in_type.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:56:27 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/12 18:58:55 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_tokenizer.h"

t_built_in_type	mn_check_built_in_type(char *s)
{
	if (ft_strcmp("cd", s) == 0)
		return (MN_CD);
	if (ft_strcmp("echo", s) == 0)
		return (MN_ECHO);
	if (ft_strcmp("env", s) == 0)
		return (MN_ENV);
	if (ft_strcmp("exit", s) == 0)
		return (MN_EXIT);
	if (ft_strcmp("pwd", s) == 0)
		return (MN_PWD);
	if (ft_strcmp("unset", s) == 0)
		return (MN_UNSET);
	if (ft_strcmp("export", s) == 0)
		return (MN_EXPORT);
	return (NOT_BUILT_IN);
}
