/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamintle <benjamintle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 03:57:41 by cfauvell          #+#    #+#             */
/*   Updated: 2019/03/13 12:27:52 by benjamintle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stdio.h>

int		main(void)
{
	char *test = "bonjour";
	unsigned int test2 = 20;
	char test3 = 'a';
	//int	*test4 = &test2;
	int i;
	int j;

	ft_putstr("\nTest1\n");
	j = printf("La fonction:	%p, %-15s, %-o, %c\n",test, test, test2, test3);
	i = ft_printf("Ma fonction:	%p, %-15s, %-o, %c\n",test, test, test2, test3);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);

	ft_putstr("\nTest2\n");
	j = printf("La fonction:	%+20.10d, %-15s, %-o, %c\n", test2, test, test2, test3);
	
	i = ft_printf("Ma fonction:	%+20.10d, %-15s, %-o, %c\n", test2, test, test2, test3);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);

	ft_putstr("\nTest3\n");
	j = printf("La fonction:	%u\n", test2);
	i = ft_printf("Ma fonction:	%u\n", test2);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);

	return (0);
}
