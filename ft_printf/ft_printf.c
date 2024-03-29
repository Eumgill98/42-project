/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:32:37 by hocjeong          #+#    #+#             */
/*   Updated: 2024/03/29 16:47:38 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	_doprintf(va_list ap, const char *format)
{
	int	printed;

	printed = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			printed += check_n_write(ap, format);
			format += 2;
		}
		else
		{
			printed += write(1, format, 1);
			format ++;
		}
	}
	return (read_size);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		printed;

	printed = 0;
	va_start(ap, format);
	printed = _doprintf(ap, format);
	va_end(ap);
	return (printed);
}
