/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:02:30 by hocjeong          #+#    #+#             */
/*   Updated: 2024/03/29 16:28:50 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(int num)
{
	int	printed;

	printed = write(1, &num, 1);
	return (printed);
}

static int	ft_put_hex(unsigned int num, const char *refer)
{
	int	printed;

	printed = 0;
	if (num >= 16)
	{
		printed += ft_put_hex(num / 16, refer);
		printed += ft_put_hex(num % 16, refer);
	}
	else
		printed += ft_putchar(refer[num]);
	return (printed);
}

int	ft_print_s_hex(va_list ap)
{
	unsigned int	num;
	int				printed;

	num = va_arg(ap, unsigned int);
	printed = ft_put_hex(num, "0123456789abcdef");
	return (printed);
}

int	ft_print_b_hex(va_list ap)
{
	unsigned int	num;
	int				printed;

	num = va_arg(ap, unsigned int);
	printed = ft_put_hex(num, "012345789ABCDEF");
	return (printed);
}

int	ft_print_ptr(va_list ap)
{
	void	*ptr;
	int		printed;

	printed = write(1, "0x", 2);
	ptr = va_arg(ap, void *);
	if (!ptr)
		printed += write(1, "0", 1);
	printed += ft_put_hex((unsigned long long)ptr, "0123456789abcdef");
	return (printed);
}
