/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btollie <btollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:52:59 by btollie           #+#    #+#             */
/*   Updated: 2018/11/13 12:07:55 by btollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *fresh_mem;

	if (!(fresh_mem = malloc(sizeof(size_t) * size)))
		return (NULL);
	while (size--)
		fresh_mem[size] = 0;
	return (fresh_mem);
}
