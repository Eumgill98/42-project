/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:27:58 by hocjeong          #+#    #+#             */
/*   Updated: 2024/06/28 21:07:02 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoil(const char *nptr, int *overflow)
{
	long long		result;
	char			*tmp;
	int				flag;

	flag = 1;
	result = 0;
	tmp = (char *)nptr;
	while (ft_isspace(*tmp))
		tmp++;
	if (*tmp == '-' || *tmp == '+')
	{
		if (*tmp == '-')
			flag *= -1;
		tmp++;
	}
	while (*tmp && (*tmp >= '0' && *tmp <= '9'))
	{
		result *= 10;
		result += (*tmp - '0');
		tmp++;
	}
	result = (flag * result);
	if (result != (int)result)
		*overflow = 1;
	return ((int)result);
}
