/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:22:04 by hocjeong          #+#    #+#             */
/*   Updated: 2024/03/29 16:59:47 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list ap)
{
	char	c;

	c = (unsigned char)va_arg(ap, int);
	return (write(1, &c, 1));
}

#include <stdio.h>
int	ft_print_str(va_list ap)
{
	char	*s;
	int		printed;

	s = va_arg(ap, char *);
	printed = 0;
	while (*s)
	{
		printed += write(1, s, 1);
		s++;
	}
	return (printed);
}
