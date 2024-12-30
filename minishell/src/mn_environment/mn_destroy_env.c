/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_destroy_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:26:42 by hocjeong          #+#    #+#             */
/*   Updated: 2024/11/27 20:34:01 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_environment.h"

void	mn_destroy_env(t_env *env)
{
	if (env->varname)
	{
		free(env->varname);
		env->varname = NULL;
	}
	if (env->value)
	{
		free(env->value);
		env->value = NULL;
	}
}
