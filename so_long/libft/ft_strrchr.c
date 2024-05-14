/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:47:13 by hocjeong          #+#    #+#             */
/*   Updated: 2024/02/27 17:03:25 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	char	*last_o;

	tmp = (char *)s;
	last_o = 0;
	while (*tmp)
	{
		if (*tmp == c)
			last_o = tmp;
		tmp++;
	}
	if (c == 0)
		return (tmp);
	return (last_o);
}
