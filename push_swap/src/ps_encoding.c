/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_encoding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:57:46 by hocjeong          #+#    #+#             */
/*   Updated: 2024/07/04 17:36:45 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int  ps_encoding(const char *command)
{
    int idx;
    int num;

    if (!command)
        return (-1);
    idx = 0;
    num = 0;
    while (command[idx])
    {
        num *= 10;
        num += command[idx];
        idx++;
    }
    return (num % 42);
}