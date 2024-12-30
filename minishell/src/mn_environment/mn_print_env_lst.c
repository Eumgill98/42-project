/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_print_env_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:45:04 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/22 19:46:02 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_environment.h"

void	mn_print_env_lst(t_env *head, int export_flag)
{
	t_env	*tmp;

	tmp = head;
	while (tmp)
	{
		if (export_flag)
		{
			printf("declare -x ");
			if (tmp->value)
				printf("%s=\"%s\"\n", tmp->varname, tmp->value);
			else
				printf("%s\n", tmp->varname);
		}
		else
			printf("%s=%s\n", tmp->varname, tmp->value);
		tmp = tmp->next;
	}
}
