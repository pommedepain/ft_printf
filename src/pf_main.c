/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
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
	int		i;
	int		j;
	int		p;
	char	*str;
	double d;
	char	c;
	
	printf("############- f -############\n");

	d = 15.51;
	printf("----test: 15.51 precision: %d ----\n",1);
	printf("NOUS\n");
	i = ft_printf("%.1f\n", d);
	printf("PRINTF\n");
	j =	printf("%.1f\n", d);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);
	
	d = 15.5;
	printf("----test: 15.5 precision: %d ----\n", 1);
	printf("NOUS\n");
	i = ft_printf("%.1f\n", d);
	printf("PRINTF\n");
	j =	printf("%.1f\n", d);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	d = 15.50;
	printf("----test: 15.50 precision: %d ----\n", 1);
	printf("NOUS\n");
	i = ft_printf("%.1f\n", d);
	printf("PRINTF\n");
	j =	printf("%.1f\n", d);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	d = 1.250;
	printf("----test: 1.250 precision: %d ----\n",1);
	printf("NOUS\n");
	i = ft_printf("%.1f\n", d);
	printf("PRINTF\n");
	j =	printf("%.1f\n", d);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	d = 1.259;
	printf("----test: 1.259 precision: %d ----\n",1);
	printf("NOUS\n");
	i = ft_printf("%.1f\n", d);
	printf("PRINTF\n");
	j =	printf("%.1f\n", d);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	d = 1.25;
	printf("----test: 1.25 precision: %d ----\n", 1);
	printf("NOUS\n");
	i = ft_printf("%.1f\n", d);
	printf("PRINTF\n");
	j =	printf("%.1f\n", d);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	d = 1.65;
	printf("----test: 1.65 precision: %d ----\n", 1);
	printf("NOUS\n");
	i = ft_printf("%.1f\n", d);
	printf("PRINTF\n");
	j =	printf("%.1f\n", d);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	d = 3.49;
	printf("----test: 3.49 precision: %d ----\n", 1);
	printf("NOUS\n");
	i = ft_printf("%.1f\n", d);
	printf("PRINTF\n");
	j =	printf("%.1f\n", d);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	d = 42.1465;
	printf("----test: 42.1465 precision: %d ----\n", 1);
	printf("NOUS\n");
	i = ft_printf("%.1f\n", d);
	printf("PRINTF\n");
	j =	printf("%.1f\n", d);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	d = 43.1466;
	printf("----test: 43.1466 precision: %d ----\n", 1);
	printf("NOUS\n");
	i = ft_printf("%.1f\n", d);
	printf("PRINTF\n");
	j =	printf("%.1f\n", d);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	d = 43.1466;
	printf("----test: 43.1466 precision: %d ----\n", 0);
	printf("NOUS\n");
	i = ft_printf("%.0f\n", d);
	printf("PRINTF\n");
	j =	printf("%.0f\n", d);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	d = 43.0;
	printf("----test: 43.0 precision: %d ----\n", 0);
	printf("NOUS\n");
	i = ft_printf("%.0f\n", d);
	printf("PRINTF\n");
	j =	printf("%.0f\n", d);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	d = 43.0;
	printf("----test: 43.0 precision: %d ----\n", 10);
	printf("NOUS\n");
	i = ft_printf("%.10f\n", d);
	printf("PRINTF\n");
	j =	printf("%.10f\n", d);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	d = -2.0 * 1.0 / 3.0;
	printf("----test: precision: -2/3 %d ----\n", 10);
	printf("NOUS\n");
	i = ft_printf("%.10f\n", d);
	printf("PRINTF\n");
	j =	printf("%.10f\n", d);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	printf("############- p -############\n");

	p = 2147483647;
	printf("----test: p 2147483647 ----\n");
	printf("NOUS\n");
	i = ft_printf("%p\n", &p);
	printf("PRINTF\n");
	j =	printf("%p\n", &p);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	p = 0;
	printf("----test: p 0 ----\n");
	printf("NOUS\n");
	i = ft_printf("%p\n", 0);
	printf("PRINTF\n");
	j =	printf("%p\n", 0);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	printf("############- o -############\n");

	p = 2147483647;
	printf("----test: o 2147483647 ----\n");
	printf("NOUS\n");
	i = ft_printf("%o\n", p);
	printf("PRINTF\n");
	j =	printf("%o\n", p);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	printf("############- x -############\n");

	p = 2147483647;
	printf("----test: x 2147483647 ----\n");
	printf("NOUS\n");
	i = ft_printf("%x\n", p);
	printf("PRINTF\n");
	j =	printf("%x\n", p);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	p = 2147483647;
	printf("----test: X 2147483647 ----\n");
	printf("NOUS\n");
	i = ft_printf("%X\n", p);
	printf("PRINTF\n");
	j =	printf("%X\n", p);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	printf("############- d -############\n");

	p = 2147483647;
	printf("----test: 2147483647 ----\n");
	printf("NOUS\n");
	i = ft_printf("%d\n", p);
	printf("PRINTF\n");
	j =	printf("%d\n", p);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	printf("############- u -############\n");

	p = 2147483647;
	printf("----test: 2147483647 ----\n");
	printf("NOUS\n");
	i = ft_printf("%u\n", p);
	printf("PRINTF\n");
	j =	printf("%u\n", p);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	printf("############- s -############\n");

	str = "YOLOSWAG";
	printf("----test: s = YOLOSWAG ----\n");
	printf("NOUS\n");
	i = ft_printf("%s\n", str);
	printf("PRINTF\n");
	j =	printf("%s\n", str);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	str = NULL;;
	printf("----test: s = NULL ----\n");
	printf("NOUS\n");
	i = ft_printf("%s\n", str);
	printf("PRINTF\n");
	j =	printf("%s\n", str);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);

	printf("############- c -############\n");

	c = 0;
	printf("----test: c = 0 ----\n");
	printf("NOUS\n");
	i = ft_printf("%c\n", c);
	printf("PRINTF\n");
	j =	printf("%c\n", c);
	printf("Nb char ft_printf = %d\nNb char printf = %d\n\n", i, j);
	
	return (0);
}
