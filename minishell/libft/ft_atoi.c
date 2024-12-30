/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:31:50 by hocjeong          #+#    #+#             */
/*   Updated: 2024/03/04 15:33:13 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		flag;
	int		result;
	char	*tmp;

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
	return (flag * result);
}
