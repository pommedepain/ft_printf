/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:30:50 by cajulien          #+#    #+#             */
/*   Updated: 2019/03/29 15:20:39 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t				len;
	unsigned long long	c;

	len = 0;
	while ((c = *(unsigned long long *)s) || 1)
	{
		if (!(c & 0xFF))
			return (len);
		if (!(c & 0xFF00))
			return (len + 1);
		if (!(c & 0xFF0000))
			return (len + 2);
		if (!(c & 0xFF000000))
			return (len + 3);
		if (!(c & 0xFF00000000))
			return (len + 4);
		if (!(c & 0xFF0000000000))
			return (len + 5);
		if (!(c & 0xFF000000000000))
			return (len + 6);
		if (!(c & 0xFF00000000000000))
			return (len + 7);
		s += 8;
		len += 8;
	}
}
