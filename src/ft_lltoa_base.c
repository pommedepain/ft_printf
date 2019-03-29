/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 01:13:00 by cajulien          #+#    #+#             */
/*   Updated: 2019/03/29 16:47:41 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lltoa_base(long long value, int b_size, char *base)
{
	int						i;
	unsigned long long		nbr;
	int						size;
	char					*to_print;

	if (value < 0)
		nbr = value * -1;
	else
		nbr = value;
	size = ft_numlen(nbr, b_size);
	(b_size == 10 && value < 0) ? size++ : 0;
	if (!(to_print = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = size;
	while (i--)
	{
		to_print[i] = base[nbr % b_size];
		(b_size != 2 && b_size != 8 && b_size != 16) ? nbr /= b_size : 0;
		b_size == 2 ? nbr >>= 1 : 0;
		b_size == 8 ? nbr >>= 3 : 0;
		b_size == 16 ? nbr >>= 4 : 0;
	}
	(b_size == 10 && value < 0) ? to_print[0] = '-' : 0;
	to_print[size] = '\0';
	return (to_print);
}
