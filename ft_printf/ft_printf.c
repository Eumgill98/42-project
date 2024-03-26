/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:32:37 by hocjeong          #+#    #+#             */
/*   Updated: 2024/03/26 15:37:12 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	_check_flag(const char *format)
{
	char	*check_flag = "cspdiuxX%";
	int	flag;

	flag = 0;
	while (check_flag[flag])
	{
		if (check_flag[flag] == *format)
			return (flag);
		flag++;
	}
	return (-1);
}

int	_check_n_write(va_list ap, const char *format);
{
	int	read_size;

	if (_check_flag(format + 1) == 0)
		// write sigle Char
	else if (_check_flag(format + 1) == 1)
		// write String
	else if (_check_flag(format + 1) == 2)
		// write Pointer 
	else if (_check_flag(format + 1) == 3)
		// write d
	else if (_check_flag(format + 1) == 4)
		// write i
	else if (_check_flag(format + 1) == 5)
		// write u
	else if (_check_flag(format + 1) == 6)
		// write x
	else if (_check_flag(format + 1) == 7)
		// write X
	else if (_check_flag(format + 1) == 8)
		// write %
	else if (_check_flag(format + 1) == -1)
		// fuck
	return (read_size);
}

int	_doprintf(va_list ap, const char *format)
{
	int	read_size;

	read_size = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
			read_size += _check_n_write(ap, format);
		else
		{
			write(1, format, 1);
			read_size++;
		}
		format++;
	}
	return (read_size);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int	read_size;

	read_size = 0;
	va_start(ap, format);
	read_size = _doprintf(ap, format);
	va_end(ap);
	return (read_size);
}
