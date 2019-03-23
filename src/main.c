/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 03:57:41 by cfauvell          #+#    #+#             */
/*   Updated: 2019/03/23 18:11:25 by pommedepin       ###   ########.fr       */
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

	printf("\nTest #5x de 42\n");
	i = ft_printf("%#5x\\0\n", 42);
	j = printf("%#5x\\0\n", 42);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);

	printf("\n########## NEXT #########\n");

	printf("\nTest -#5x de 42\n");
	i = ft_printf("%-#5x\\0\n", 42);
	j = printf("%-#5x\\0\n", 42);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);

	printf("\n########## NEXT #########\n");

	printf("\nTest #5X de 42\n");
	i = ft_printf("%#5X\\0\n", 42);
	j = printf("%#5X\\0\n", 42);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);

	printf("\n########## NEXT #########\n");

	printf("\nTest -#5X de 42\n");
	i = ft_printf("%-#5X\\0\n", 42);
	j = printf("%-#5X\\0\n", 42);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);

	printf("\n########## NEXT #########\n");

	printf("\nTest #5o de 42\n");
	i = ft_printf("%#5o\\0\n", 42);
	j = printf("%#5o\\0\n", 42);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);

	printf("\n########## NEXT #########\n");

	printf("\nTest -#5o de 42\n");
	i = ft_printf("%-#5o\\0\n", 42);
	j = printf("%-#5o\\0\n", 42);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);

	printf("\n########## NEXT #########\n");

	printf("\nTest pourcent de rien\n");
	i = ft_printf("% \\0\n");
	j = printf("% \\0\n");
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);

	printf("\n########## NEXT #########\n");

	printf("\nTest pourcent h de rien\n");
	i = ft_printf("% h\\0\n");
	j = printf("% h\\0\n");
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);

	/*
	printf("\nTest o de 0\n");
	i = ft_printf("%o = 1\n", 0);
	j = printf("%o = 1\n", 0);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);

	printf("\n########## NEXT #########\n");

	printf("\nTest .2o de 0\n"); // affiche 0 au lieu de rien + un char en trop
	i = ft_printf("%.2o = 1\n", 0);
	j = printf("%.2o = 1\n", 0);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);

	printf("\n########## NEXT #########\n");

	printf("\nTest .0o de 0\n"); // affiche 0 au lieu de rien + un char en trop
	i = ft_printf("%.0o = 1\n", 0);
	j = printf("%.0o = 1\n", 0);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);	

	printf("\n########## NEXT #########\n");

	printf("\nTest #.o de 0\n"); // un char en trop
	i = ft_printf("%#.o = 1\n", 0);
	j = printf("%#.o = 1\n", 0);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);

	printf("\n########## NEXT #########\n");

	printf("\nTest #.2o de 0\n"); // un char en trop
	i = ft_printf("%#.2o = 1\n", 0);
	j = printf("%#.2o = 1\n", 0);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);

	printf("\n########## NEXT #########\n");

	printf("\nTest #6o de 0\n"); // affiche deux 0 au lieu d'un
	i = ft_printf("%#6o = 1\n", 0);
	j = printf("%#6o = 1\n", 0);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);

	printf("\n########## NEXT #########\n");

	printf("\nTest -#6o de 0\n"); // affiche deux 0 au lieu d'un
	i = ft_printf("%-#6o = 1\n", 0);
	j = printf("%-#6o = 1\n", 0);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);

	printf("\n########## NEXT #########\n");

	printf("\nTest 5.o de 0\n"); // affiche 0 au lieu de rien + un char en trop
	i = ft_printf("%5.o = 1\n", 0);
	j = printf("%5.o = 1\n", 0);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);

	printf("\n########## NEXT #########\n");

	printf("\nTest 5.0o de 0\n"); // affiche 0 au lieu de rien + un char en trop
	i = ft_printf("%5.0o = 1\n", 0);
	j = printf("%5.0o = 1\n", 0);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);

	printf("\n########## NEXT #########\n");

	printf("\nTest #6o de 25000\n");
	i = ft_printf("%#6o = 1\n", 2500);
	j = printf("%#6o = 1\n", 2500);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);
	
	printf("\n########## NEXT #########\n");

	printf("\nTest -#6o de 25000\n");
	i = ft_printf("%-#6o = 1\n", 2500);
	j = printf("%-#6o = 1\n", 2500);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);*/


	return (0);
}
