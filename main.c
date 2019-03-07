/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 13:12:01 by cajulien          #+#    #+#             */
/*   Updated: 2019/03/07 15:38:18 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "address.h"

int		main(void)
{
	double		i;
	i = 0;
	char		*tmp;
	printf("%p\n", &i);
	tmp = print_address((void *)&i);
	ft_putendl(tmp);
	free(tmp);
}
