/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_check_plus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:36:14 by hocjeong          #+#    #+#             */
/*   Updated: 2024/12/22 21:42:43 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_environment.h"

int	mn_check_plus(char **varname)
{
	char	*tmp;
	int		len;

	tmp = *varname;
	len = ft_strlen(tmp);
	if (len > 0 && tmp[len - 1] == '+')
	{
		tmp[len - 1] = '\0';
		return (1);
	}
	return (0);
}
