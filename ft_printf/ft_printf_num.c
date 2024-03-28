/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:22:04 by hocjeong          #+#    #+#             */
/*   Updated: 2024/03/28 17:15:01 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_int(int num)
{
	int	printed;

	printed = 0;
	if (n == -2147483648)
		printed += write(1, "-2147483648", 11);
	else if (num < 0)
	{
		printed += write(1, "-", 1);
		printed += ft_putnbr(-num, printed);
	}
	else if (num < 10 && num >= 0)
	{
		num = num + '0';
		printed += write(1, &num, 1);
	}
	else
	{
		printed += ft_putnbr(num / 10);
		printed += ft_putnbr(num % 10);
	}
	return (printed);
}

static int	ft_putnbr_unit(unsigned int num)
{
	int	printed;

	printed = 0;
	if (num < 10 && num >= 0)
	{
		num = num + '0';
		printed += write(1, &num, 1);
	}
	else
	{
		printed += ft_putnbr(num / 10);
		printed += ft_putnbr(num % 10);
	}
	return (printed);
}

int	ft_print_digit(va_list ap)
{
	int	d;

	d = va_arg(ap, int) + '0';
	return (write(1, &d, 1));
}

int	ft_print_int(va_list ap)
{
	int	num;
	int	printed;

	num = va_arg(ap, int);
	printed = ft_putnbr_int(num);
	return (printed);
}

int	ft_print_unint(va_list ap)
{
	unsigned int	num;
	int				printed;

	num = va_arg(ap, unsigned int);
	printed = ft_putnbr_unit(num);
	return (printed);
}
