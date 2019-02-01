/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:00:48 by cajulien          #+#    #+#             */
/*   Updated: 2019/02/01 15:52:59 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			main(int ac, char **av)
{
    t_data		*data;
	//int			i = 0;

	if (ac != 2)
		return (0);
	if(!(data = create_elem(NULL)))
		return (0);
	parse(av[1], &data);
	show_data(&data);
	free_data(&data);
	/*
	while (1)   // pour pouvoir utiliser leaks en lieu et place de valgrind
		i++;
	*/
	return (0);
}