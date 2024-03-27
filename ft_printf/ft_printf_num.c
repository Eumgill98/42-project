/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:22:04 by hocjeong          #+#    #+#             */
/*   Updated: 2024/03/26 15:12:00 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_digit(va_list ap)
{
    int d;

    d = va_arg(ap, int) + '0';
    return (write(1, &d, 1));
}

int ft_print_int(va_list ap)
{
    int num;
    int printed

    num = va_arg(ap, int);
    // printed = ft_print_num(num);
    return (printed);
}

int ft_print_unint(va_list ap)
{
    unsigned int num;
    int printed 

    num = va_arg(ap, unsigned int);
    // printed = ft_print_num(num);
    return (printed);
}

