/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:22:04 by hocjeong          #+#    #+#             */
/*   Updated: 2024/03/28 16:37:16 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

//printf
int	ft_printf(const char *format, ...);

//utils
int	check_n_write(va_list ap, const char *format);

//print_str.c
int	ft_print_char(va_list ap);
int	ft_print_str(va_list ap);

//print_num.c
int	ft_print_digit(va_list ap);
int	ft_print_int(va_list ap);
int	ft_print_unint(va_list ap);

//print_hex family
int	ft_print_ptr(va_list ap);
int	ft_print_s_hex(va_list ap);
int	ft_print_b_hex(va_list ap);

//print_percent & other
int	ft_print_percent(va_list ap);
int	ft_print_other(const char *format);

#endif
