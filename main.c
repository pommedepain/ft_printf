/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamintle <benjamintle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 03:57:41 by cfauvell          #+#    #+#             */
/*   Updated: 2019/03/07 15:57:32 by benjamintle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		main(void)
{
	char *test = "bonjour";
	int test2 = 20;
	char test3 = 'a';
	//int	*test4 = &test2;
	int i;
	int j;

	ft_putstr("\nTest1\n");
	i = ft_printf("Ma fonction:%*.*d, %-15s, %-o, %c\n",10,25, test2, test, test2, test3);
	j = printf("La fonction:%.*d, %-15s, %-o, %c\n",25, test2, test, test2, test3);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);

	ft_putstr("\nTest2\n");
	i = ft_printf("Ma fonction:%+20.10d, %-15s, %-o, %c\n", test2, test, test2, test3);
	j = printf("La fonction:%+20.10d, %-15s, %-o, %c\n", test2, test, test2, test3);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);
	return (0);
}
