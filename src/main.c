/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 03:57:41 by cfauvell          #+#    #+#             */
/*   Updated: 2019/03/15 12:03:29 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stdio.h>

int		main(void)
{
	//char *test = "bonjour";
	//unsigned int test2 = 20;
	//char test3 = 'a';

	//int	*test4 = &test2;
	int i;
	int j;

	/*printf("\nTest1\n");
	i = ft_printf("Ma fonction:	%p, %-15s, %-o, %c\n",test, test, test2, test3);
	j = printf("La fonction:	%p, %-15s, %-o, %c\n",test, test, test2, test3);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);

	printf("\nTest2\n");
	i = ft_printf("Ma fonction:	%+20.10d, %-15s, %-o, %c\n", test2, test, test2, test3);
	j = printf("La fonction:	%+20.10d, %-15s, %-o, %c\n", test2, test, test2, test3);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);*/

	// quand en ll#x, output pas le même que les test d'undefined behavior
	printf("\nTest3 ll#x de 9223372036854775807\n");
	i = ft_printf("%#llx\n", 9223372036854775807);
	j = printf("%#llx\n", (unsigned long long)9223372036854775807);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);

	// Mauvais malloc de 2 de trop avec le - --> à voir dans conversion.c
	printf("\nTest3 -#6o de 25000\n");
	i = ft_printf("%-#6o\n", 25000);
	j = printf("%-#6o\n", 25000);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);

	/*printf("\nTest3 5.x 5.1x de 0\n");
	i = ft_printf("%5.x %5.0x\n", 1, 1);
	j = printf("%5.x %5.0x\n", 1, 1);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);*/


	/*ft_putstr("\nTest Unitaire u\n");
	ft_putstr(ft_ulltoa_base((unsigned int)-21, 10, _x_));
	ft_putchar('\n');
	j = printf("%lu\n", -21);
	printf("Nb char printf = %d\n", j);*/

	/*ft_putstr("\nTest4 u\n");
	i = ft_printf("%u\n", 4294967295);
	j = printf("%u\n", (unsigned int)4294967295);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);

	ft_putstr("\nTest Unitaire u\n");
	ft_putstr(ft_ltoa_base(4294967295, 10));
	ft_putchar('\n');
	j = printf("%u\n", (unsigned int)4294967295);
	printf("Nb char printf = %d\n", j);*/

	/*ft_putstr("\nTest5 X\n");
	i = ft_printf("%X\n", -42);
	j = printf("%X\n", -42);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);

	ft_putstr("\nTest Unitaire X\n");
	ft_putstr(ft_ulltoa_base((unsigned int)-42, 16, _X_));
	ft_putchar('\n');
	j = printf("%X\n", -42);
	printf("Nb char printf = %d\n", j);*/

	// Actuellement 29 fail test sur 197 dont 12 qui ne nous concerne pas :
	// Car conversion "z", "j" ou "U"

	return (0);
}
