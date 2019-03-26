/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 03:57:41 by cfauvell          #+#    #+#             */
/*   Updated: 2019/03/26 12:19:40 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stdio.h>
#include <float.h>

int		main(void)
{
	int i;
	int j;
	int		p;
	/*printf("\nTest pourcent de rien\n");
	i = ft_printf("% \\0\n");
	j = printf("% \\0\n");
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);

	printf("\n########## NEXT #########\n");

	printf("\nTest pourcent h de rien\n");
	i = ft_printf("% h\\0\n");
	j = printf("% h\\0\n");
	printf("Nb char ft_printf = %d\nNb char printf = %d\n", i, j);*/

	double d;

	d = 15.51;
	printf("----test: %f precision: %d ----\n", d, 1);
	printf("NOUS\n");
	i = ft_printf("%.1f\n", d);
	printf("PRINTF\n");
	j =	printf("%.1f\n", d);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);
	
	d = 15.5;
	printf("----test: %f precision: %d ----\n", d, 1);
	printf("NOUS\n");
	i = ft_printf("%.1f\n", d);
	printf("PRINTF\n");
	j =	printf("%.1f\n", d);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	d = 15.50;
	printf("----test: %f precision: %d ----\n", d, 1);
	printf("NOUS\n");
	i = ft_printf("%.1f\n", d);
	printf("PRINTF\n");
	j =	printf("%.1f\n", d);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	d = 1.250;
	printf("----test: %f precision: %d ----\n", d, 1);
	printf("NOUS\n");
	i = ft_printf("%.1f\n", d);
	printf("PRINTF\n");
	j =	printf("%.1f\n", d);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	d = 1.259;
	printf("----test: %f precision: %d ----\n", d, 1);
	printf("NOUS\n");
	i = ft_printf("%.1f\n", d);
	printf("PRINTF\n");
	j =	printf("%.1f\n", d);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	d = 1.25;
	printf("----test: %f precision: %d ----\n", d, 1);
	printf("NOUS\n");
	i = ft_printf("%.1f\n", d);
	printf("PRINTF\n");
	j =	printf("%.1f\n", d);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	d = 1.65;
	printf("----test: %f precision: %d ----\n", d, 1);
	printf("NOUS\n");
	i = ft_printf("%.1f\n", d);
	printf("PRINTF\n");
	j =	printf("%.1f\n", d);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	d = 3.49;
	printf("----test: %f precision: %d ----\n", d, 1);
	printf("NOUS\n");
	i = ft_printf("%.1f\n", d);
	printf("PRINTF\n");
	j =	printf("%.1f\n", d);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	d = 42.1465;
	printf("----test: %f precision: %d ----\n", d, 1);
	printf("NOUS\n");
	i = ft_printf("%.1f\n", d);
	printf("PRINTF\n");
	j =	printf("%.1f\n", d);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	d = 43.1466;
	printf("----test: %f precision: %d ----\n", d, 1);
	printf("NOUS\n");
	i = ft_printf("%.1f\n", d);
	printf("PRINTF\n");
	j =	printf("%.1f\n", d);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	d = 43.1466;
	printf("----test: %f precision: %d ----\n", d, 0);
	printf("NOUS\n");
	i = ft_printf("%.0f\n", d);
	printf("PRINTF\n");
	j =	printf("%.0f\n", d);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	d = 43.0;
	printf("----test: %f precision: %d ----\n", d, 0);
	printf("NOUS\n");
	i = ft_printf("%.0f\n", d);
	printf("PRINTF\n");
	j =	printf("%.0f\n", d);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	d = 43.0;
	printf("----test: %f precision: %d ----\n", d, 10);
	printf("NOUS\n");
	i = ft_printf("%.10f\n", d);
	printf("PRINTF\n");
	j =	printf("%.10f\n", d);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	d = -2.0 * 1.0 / 3.0;
	printf("----test: %f precision: %d ----\n", d, 10);
	printf("NOUS\n");
	i = ft_printf("%.10f\n", d);
	printf("PRINTF\n");
	j =	printf("%.10f\n", d);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	p = 2147483647;
	printf("----test: p ----");
	printf("NOUS\n");
	i = ft_printf("%p\n", &p);
	printf("PRINTF\n");
	j =	printf("%p\n", &p);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	p = 2147483647;
	printf("----test: o ----");
	printf("NOUS\n");
	i = ft_printf("%o\n", p);
	printf("PRINTF\n");
	j =	printf("%o\n", p);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	p = 2147483647;
	printf("----test: x ----");
	printf("NOUS\n");
	i = ft_printf("%x\n", p);
	printf("PRINTF\n");
	j =	printf("%x\n", p);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);
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
