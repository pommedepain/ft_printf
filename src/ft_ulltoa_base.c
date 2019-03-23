/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 01:14:12 by cajulien          #+#    #+#             */
/*   Updated: 2019/03/23 11:14:33 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ulltoa_base(unsigned long long value, int base_size, char *base)
{
	int						i;
	int						size;
	char					*to_print;

	size = ft_numlen(value, base_size);
	if (!(to_print = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = size;
	while (i--)
	{
		to_print[i] = base[value % base_size];
		value /= base_size;
	}
	to_print[size] = '\0';
	return (to_print);
}
