/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btollie <btollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:49:17 by btollie           #+#    #+#             */
/*   Updated: 2018/11/22 14:13:14 by btollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*a;
	unsigned char		*b;

	a = (unsigned char *)src;
	b = (unsigned char *)dst;
	while (n--)
		*b++ = *a++;
	return (dst);
}
