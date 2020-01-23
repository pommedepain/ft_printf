/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 01:42:03 by cajulien          #+#    #+#             */
/*   Updated: 2019/03/29 16:49:47 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numlen(unsigned long long int n, int b_size)
{
	int		i;

	i = 1;
	while (n >= (unsigned long long)b_size)
	{
		(b_size != 2 && b_size != 8 && b_size != 16) ? n /= b_size : 0;
		b_size == 2 ? n >>= 1 : 0;
		b_size == 8 ? n >>= 3 : 0;
		b_size == 16 ? n >>= 4 : 0;
		i++;
	}
	return (i);
}
