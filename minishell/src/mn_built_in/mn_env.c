/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:40:29 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/08 17:41:52 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_built_in.h"

void	mn_env(t_env *envs)
{
	mn_print_env_lst(envs, 0);
}
