/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:22:04 by hocjeong          #+#    #+#             */
/*   Updated: 2024/03/26 15:12:00 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	_check_flag(const char *format)
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

int	check_n_write(va_list ap, const char *format);
{
	int	printed;

	if (_check_flag(format + 1) == 0)
		printed = ft_print_char(ap);
	else if (_check_flag(format + 1) == 1)
		printed = ft_print_str(ap);
	else if (_check_flag(format + 1) == 2)
		// printed = ft_print_ptr();
	else if (_check_flag(format + 1) == 3)
		printed = ft_print_digit();
	else if (_check_flag(format + 1) == 4)
		// printed = ft_print_int();
	else if (_check_flag(format + 1) == 5)
		// printed = ft_print_unint();
	else if (_check_flag(format + 1) == 6)
		// printed = ft_print_s_hex();
	else if (_check_flag(format + 1) == 7)
		// printed = ft_print_b_hex();
	else if (_check_flag(format + 1) == 8)
		// printed = ft_print_percent();
	else if (_check_flag(format + 1) == -1)
		// printed = ft_print_other();
	return (printed);
}