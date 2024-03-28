/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:22:04 by hocjeong          #+#    #+#             */
/*   Updated: 2024/03/28 17:15:17 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	_check_flag(const char *format, const char *check_flag)
{
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

int	check_n_write(va_list ap, const char *format)
{
	int	printed;

	if (_check_flag(format + 1, "cspdiuxX%") == 0)
		printed = ft_print_char(ap);
	else if (_check_flag(format + 1, "cspdiuxX%") == 1)
		printed = ft_print_str(ap);
	else if (_check_flag(format + 1, "cspdiuxX%") == 2)
		// printed = ft_print_ptr();
	else if (_check_flag(format + 1, "cspdiuxX%") == 3)
		printed = ft_print_digit(ap);
	else if (_check_flag(format + 1, "cspdiuxX%") == 4)
		printed = ft_print_int(ap);
	else if (_check_flag(format + 1, "cspdiuxX%") == 5)
		printed = ft_print_unint(ap);
	else if (_check_flag(format + 1, "cspdiuxX%") == 6)
		// printed = ft_print_s_hex();
	else if (_check_flag(format + 1, "cspdiuxX%") == 7)
		// printed = ft_print_b_hex();
	else if (_check_flag(format + 1, "cspdiuxX%") == 8)
		// printed = ft_print_percent();
	else if (_check_flag(format + 1, "cspdiuxX%") == -1)
		// printed = ft_print_other();
	return (printed);
}
