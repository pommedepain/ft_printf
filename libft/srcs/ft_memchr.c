/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamintle <benjamintle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:54:33 by btollie           #+#    #+#             */
/*   Updated: 2018/11/10 12:42:08 by benjamintle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*source;
	unsigned char		tofind;
	size_t				i;

	i = 0;
	tofind = (unsigned char)c;
	source = (unsigned char *)s;
	while (i < n)
	{
		if (*source == tofind)
			return (source);
		else
		{
			source++;
			i++;
		}
	}
	return (NULL);
}
