/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 03:57:41 by cfauvell          #+#    #+#             */
/*   Updated: 2019/03/25 16:55:41 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stdio.h>
#include <float.h>

int		main(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	
	printf("\nTest pourcent de rien\n");
	i = ft_printf("%s%s%s%s%s\n", "1", "2", "3", "4", "5");
	j = printf("%s%s%s%s%s\n", "1", "2", "3", "4", "5");
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);

	printf("\n########## NEXT #########\n");

	printf("\nTest pourcent h de rien\n");
	i = ft_printf("%s, % h;\n", "coucou");
	j = printf("%s % h;\n", "coucou");
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);

	printf("\n########## NEXT #########\n");

	printf("\nTest #x de 42\n");
	i = ft_printf("%#x;\n", 42);
	j = printf("%#x;\n", 42);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);

	printf("\n########## NEXT #########\n");

	printf("\nTest 05pourcent de rien\n");
	i = ft_printf("%05%;\n", 42);
	j = printf("%05%;\n", 42);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);

	/*double d;

	d = 258.01;
	printf("NOUS\n");
	i = ft_printf("%f\n", d);
	printf("PRINTF\n");
	j =	printf("%f\n", d);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);
	
	d = 258.01;
	printf("NOUS\n");
	i = ft_printf("%f\n", d);
	printf("PRINTF\n");
	j =	printf("%f\n", d);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);*/
	/*d = -2 * 1.0 / 3.0;
	str = ft_round(ft_double(d), 6);
	printf("moi : \n");
	ft_putendl(str);
	free(str);
	printf("printf : \n");
	printf("%.17f\n", d);

	d = -1.75000;
	printf("moi : \n");
	str = ft_round(ft_double(d), 1);
	ft_putendl(str);
	printf("printf : \n");
	printf("%.1f\n", d);

	d = 37.151;
	printf("moi : \n");
	str = ft_round(ft_double(d), 1);
	ft_putendl(str);
	printf("printf : \n");
	printf("%.1f\n", d);

	d = (double)(1.0 / (2147483));
	printf("moi : \n");
	str = ft_round(ft_double(d), 10);
	ft_putendl(str);
	printf("printf : \n");
	printf("%.10f\n", d);

	d2 = (long double)FLT_MIN;
	printf("moi : \n");
	str = ft_round(ft_double(d), 6);
	ft_putendl(str);
	printf("printf : \n");
	printf("%.Lf\n", d2);

	d = FLT_MAX / 2.0;
	printf("moi : \n");
	ft_putendl(ft_double(d));
	printf("printf : \n");
	printf("%f\n", d);
	//ft_putnbr(printf("%c\n", (int)0));
	//ft_putchar('\0');
*/
	return (0);
}
