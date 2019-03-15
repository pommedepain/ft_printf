/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 01:13:00 by cajulien          #+#    #+#             */
/*   Updated: 2019/03/12 10:41:45 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lltoa_base(long long value, int base_size, char *base)
{
	int						i;
	unsigned long long		nbr;
	int						size;
	char					*to_print;

	if (value < 0)
		nbr = value * -1;
	else
		nbr = value;
	size = ft_numlen(nbr, base_size);
	(base_size == 10 && value < 0) ? size++ : 0;
	if (!(to_print = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = size;
	while (i--)
	{
		to_print[i] = base[nbr % base_size];
		nbr /= base_size;
	}
	(base_size == 10 && value < 0) ? to_print[0] = '-' : 0;
	to_print[size] = '\0';
	return (to_print);
}
