/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:22:04 by hocjeong          #+#    #+#             */
/*   Updated: 2024/04/05 16:50:19 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list ap)
{
	char	c;

	c = (unsigned char)va_arg(ap, int);
	return (write(1, &c, 1));
}

int	ft_print_str(va_list ap)
{
	char	*s;
	int		printed;

	s = va_arg(ap, char *);
	if (!s)
	{
		printed = write(1, "(null)", 6);
		return (printed);
	}
	printed = 0;
	while (*s)
	{
		printed += write(1, s, 1);
		s++;
	}
	return (printed);
}
