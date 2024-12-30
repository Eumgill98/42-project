/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_new_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:36:01 by hocjeong          #+#    #+#             */
/*   Updated: 2024/11/27 21:16:45 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_environment.h"

static int	check_varname_value(char *varname, char *value)
{
	if (varname == NULL || value == NULL)
		return (-1);
	return (0);
}

static void	init_new(t_env *new)
{
	new->value = NULL;
	new->varname = NULL;
}

t_env	*mn_new_env(char *varname, char *value)
{
	t_env	*new;

	if (check_varname_value(varname, value) == 1)
		return (NULL);
	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	init_new(new);
	new->varname = ft_strdup(varname);
	if (value)
		new->value = ft_strdup(value);
	if (new->varname == NULL || (value && new->value == NULL))
	{
		mn_destroy_env(new);
		free(new);
		return (NULL);
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
