/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocjeong <hocjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:21:30 by hocjeong          #+#    #+#             */
/*   Updated: 2024/04/01 15:13:37 by hocjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	char	c = 'c';
	char	*a = "abcde";
	int	b =  0;
	unsigned int d = 515151;	

	//original
	printf("c : %c\n", c); 
	printf("s : %s\n", a);
	printf("p (char *a) : %p\n", &b);
	printf("d : %d\n", b);
	printf("i : %i\n", b);
	printf("u : %u\n", d);
	printf("x : %x\n", b);
	printf("X : %X\n", b);
	printf("print %% : %%\n");

	int	size_of_s = printf("%s\n", a);	
	printf("check printf returns :  %d\n", size_of_s);
	printf("=======================\n");

	//ft_printf
	ft_printf("c : %c\n", c); 
	ft_printf("s : %s\n", a);
	ft_printf("p (char *a) : %p\n", &b);
	ft_printf("d : %d\n", b);
	ft_printf("i : %i\n", b);
	ft_printf("u : %u\n", d);
	ft_printf("x : %x\n", b);
	ft_printf("X : %X\n", b);
	ft_printf("print %% : %%\n");
}
