/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 01:14:12 by cajulien          #+#    #+#             */
/*   Updated: 2019/03/29 16:46:08 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ulltoa_base(unsigned long long n, int b_size, char *base)
{
	int						i;
	int						size;
	char					*to_print;

	size = ft_numlen(n, b_size);
	if (!(to_print = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = size;
	while (i--)
	{
		to_print[i] = base[n % b_size];
		(b_size != 2 && b_size != 8 && b_size != 16) ? n /= b_size : 0;
		b_size == 2 ? n >>= 1 : 0;
		b_size == 8 ? n >>= 3 : 0;
		b_size == 16 ? n >>= 4 : 0;
	}
	to_print[size] = '\0';
	return (to_print);
}
