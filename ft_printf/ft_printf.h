/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:22:04 by hocjeong          #+#    #+#             */
/*   Updated: 2024/03/29 17:01:17 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);

int	check_n_write(va_list ap, const char *format);

int	ft_print_char(va_list ap);
int	ft_print_str(va_list ap);

int	ft_print_int(va_list ap);
int	ft_print_unint(va_list ap);

int	ft_print_ptr(va_list ap);
int	ft_print_s_hex(va_list ap);
int	ft_print_b_hex(va_list ap);

#endif
