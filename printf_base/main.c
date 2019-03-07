/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 03:57:41 by cfauvell          #+#    #+#             */
/*   Updated: 2019/03/06 17:22:47 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	char *test = "bonjour";
	int test2 = 20;
	char test3 = 'a';
	//int	*test4 = &test2;
	int i;
	int j;

	i = ft_printf("Ma fonction:%+20.10d, %-15s, %-o, %c\n", test2, test, test2, test3);
	j = printf("La fonction:%+20.10d, %-15s, %-o, %c\n", test2, test, test2, test3);
	ft_putnbr(i);
	ft_putchar('\n');
	ft_putnbr(j);
	return (0);
}
