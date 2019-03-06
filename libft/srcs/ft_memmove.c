/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btollie <btollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:48:57 by btollie           #+#    #+#             */
/*   Updated: 2018/11/22 14:18:28 by btollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*source;
	size_t	i;

	i = 0;
	if (len > 0)
	{
		dest = (char *)dst;
		source = (char *)src;
		if (source > dest)
		{
			while (len--)
				*dest++ = *source++;
		}
		else
		{
			while (i++ < len)
				dest[len - i] = source[len - i];
		}
	}
	return (dst);
}
