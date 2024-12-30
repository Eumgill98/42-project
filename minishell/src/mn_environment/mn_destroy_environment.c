/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_destroy_environment.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:04:50 by hocjeong          #+#    #+#             */
/*   Updated: 2024/11/27 21:08:38 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_environment.h"

void	mn_destroy_environment(t_environment *environment)
{
	if (environment->envs)
	{
		mn_destroy_env_lst(environment->envs);
		environment->envs = NULL;
	}
	if (environment->exports)
	{
		mn_destroy_env_lst(environment->exports);
		environment->exports = NULL;
	}
}
